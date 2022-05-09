/////////////////////////////////////////////////////////////////////////////
// Name:        view_slur.cpp
// Author:      Laurent Pugin
// Created:     2018
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include "view.h"

//----------------------------------------------------------------------------

#include <assert.h>
#include <iostream>
#include <sstream>

//----------------------------------------------------------------------------

#include "bboxdevicecontext.h"
#include "comparison.h"
#include "devicecontext.h"
#include "doc.h"
#include "ftrem.h"
#include "functorparams.h"
#include "layer.h"
#include "layerelement.h"
#include "measure.h"
#include "note.h"
#include "options.h"
#include "slur.h"
#include "staff.h"
#include "system.h"
#include "timeinterface.h"
#include "vrv.h"

namespace vrv {

//----------------------------------------------------------------------------
// View - Slur
//----------------------------------------------------------------------------

void View::DrawSlur(DeviceContext *dc, Slur *slur, int x1, int x2, Staff *staff, char spanningType, Object *graphic)
{
    assert(dc);
    assert(slur);
    assert(staff);

    FloatingPositioner *positioner = slur->GetCurrentFloatingPositioner();
    assert(positioner && positioner->Is(FLOATING_CURVE_POSITIONER));
    FloatingCurvePositioner *curve = vrv_cast<FloatingCurvePositioner *>(positioner);
    assert(curve);

    if ((this->GetSlurHandling() == SlurHandling::Initialize) && dc->Is(BBOX_DEVICE_CONTEXT)
        && (curve->GetDir() == curvature_CURVEDIR_NONE || curve->IsCrossStaff())) {
        slur->SetCachedDrawingX12(x1, x2);
        this->DrawSlurInitial(curve, slur, x1, x2, staff, spanningType);
    }

    Point points[4];
    curve->GetPoints(points);

    if (graphic)
        dc->ResumeGraphic(graphic, graphic->GetUuid());
    else
        dc->StartGraphic(slur, "", slur->GetUuid(), false);

    int penStyle = AxSOLID;
    switch (slur->GetLform()) {
        case LINEFORM_dashed: penStyle = AxSHORT_DASH; break;
        case LINEFORM_dotted: penStyle = AxDOT; break;
        case LINEFORM_wavy:
        // TODO: Implement wavy slur.
        default: break;
    }
    const int penWidth
        = m_doc->GetOptions()->m_slurEndpointThickness.GetValue() * m_doc->GetDrawingUnit(staff->m_drawingStaffSize);
    const double thicknessCoefficient
        = BoundingBox::GetBezierThicknessCoefficient(points, curve->GetThickness(), penWidth);
    this->DrawThickBezierCurve(
        dc, points, thicknessCoefficient * curve->GetThickness(), staff->m_drawingStaffSize, penWidth, penStyle);

    /*
    int i;
    for (i = 0; i <= 10; ++i) {
        Point p = BoundingBox::CalcDeCasteljau(points, (double)i / 10.0);
        this->DrawDot(dc, p.x, p.y, staff->m_drawingStaffSize);
    }
    */

    if (graphic)
        dc->EndResumedGraphic(graphic, this);
    else
        dc->EndGraphic(slur, this);
}

void View::DrawSlurInitial(FloatingCurvePositioner *curve, Slur *slur, int x1, int x2, Staff *staff, char spanningType)
{
    LayerElement *start = slur->GetStart();
    LayerElement *end = slur->GetEnd();

    if (!start || !end) return;

    const curvature_CURVEDIR drawingCurveDir = slur->CalcDrawingCurveDir(spanningType);

    const std::pair<Point, Point> endPoints = slur->CalcEndPoints(m_doc, staff, drawingCurveDir, spanningType);

    Point points[4];
    points[0] = endPoints.first;
    points[3] = endPoints.second;

    this->CalcInitialSlur(curve, slur, staff, drawingCurveDir, points);
    int thickness = m_doc->GetDrawingUnit(staff->m_drawingStaffSize) * m_options->m_slurMidpointThickness.GetValue();

    curve->UpdateCurveParams(points, thickness, drawingCurveDir);

    slur->AddPositionerToArticulations(curve, drawingCurveDir, spanningType);
}

void View::CalcInitialSlur(
    FloatingCurvePositioner *curve, Slur *slur, Staff *staff, curvature_CURVEDIR curveDir, Point points[4])
{
    // For now we pick C1 = P1 and C2 = P2
    BezierCurve bezier(points[0], points[0], points[3], points[3]);
    slur->InitBezierControlSides(bezier, curveDir);

    /************** content **************/

    const SpannedElements spannedElements = slur->CollectSpannedElements(staff, bezier.p1.x, bezier.p2.x);
    slur->AddSpannedElements(curve, spannedElements, staff, bezier.p1.x, bezier.p2.x);

    /************** angle **************/

    const bool dontAdjustAngle = curve->IsCrossStaff() || slur->GetStart()->IsGraceNote();
    const float nonAdjustedAngle
        = (bezier.p2 == bezier.p1) ? 0 : atan2(bezier.p2.y - bezier.p1.y, bezier.p2.x - bezier.p1.x);
    const float slurAngle
        = dontAdjustAngle ? nonAdjustedAngle : slur->GetAdjustedSlurAngle(m_doc, bezier.p1, bezier.p2, curveDir);
    if (curveDir != curvature_CURVEDIR_mixed) {
        bezier.p2 = BoundingBox::CalcPositionAfterRotation(bezier.p2, -slurAngle, bezier.p1);
    }

    /************** control points **************/

    if (slur->HasBulge()) {
        bezier.CalcInitialControlPointParams();
    }
    else {
        bezier.CalcInitialControlPointParams(m_doc, slurAngle, staff->m_drawingStaffSize);
    }
    bezier.UpdateControlPoints();
    if (curveDir != curvature_CURVEDIR_mixed) {
        bezier.Rotate(slurAngle, bezier.p1);
    }

    points[0] = bezier.p1;
    points[1] = bezier.c1;
    points[2] = bezier.c2;
    points[3] = bezier.p2;
}

} // namespace vrv
