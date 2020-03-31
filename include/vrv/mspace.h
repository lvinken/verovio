/////////////////////////////////////////////////////////////////////////////
// Name:        mspace.h
// Author:      Klaus Rettinghaus
// Created:     2019
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_MSPACE_H__
#define __VRV_MSPACE_H__

#include "durationinterface.h"
#include "layerelement.h"

namespace vrv {

//----------------------------------------------------------------------------
// MSpace
//----------------------------------------------------------------------------

/**
 * This class models the MEI <space> element.
 */
class MSpace : public LayerElement, public DurationInterface {
public:
    /**
     * @name Constructors, destructors, reset and class name methods
     * Reset method resets all attribute classes
     */
    ///@{
    MSpace();
    virtual ~MSpace();
    virtual Object *Clone() const { return new MSpace(*this); }
    virtual void Reset();
    virtual std::string GetClassName() const { return "MSpace"; }
    virtual ClassId GetClassId() const { return MSPACE; }
    ///@}

    /**
     * @name Getter to interfaces
     */
    ///@{
    virtual DurationInterface *GetDurationInterface() { return dynamic_cast<DurationInterface *>(this); }
    ///@}

    //----------//
    // Functors //
    //----------//

private:
    //
public:
    //
private:
};

} // namespace vrv

#endif
