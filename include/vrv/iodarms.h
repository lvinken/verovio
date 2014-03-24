/////////////////////////////////////////////////////////////////////////////
// Name:        iodarms.h
// Author:      Rodolfo Zitellini
// Created:     02/07/2012
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef __VRV_IODARMS_H__
#define __VRV_IODARMS_H__

#include <string>
#include <vector>

#include "io.h"

namespace vrv {

class Doc;
class Layer;
class Measure;
class Staff;
class Tie;

//----------------------------------------------------------------------------
// DarmsInput
//----------------------------------------------------------------------------

#define ASCII_NUMBER_OFFSET 0x30 // for homebrewed char to int

typedef struct _pitchmap {
    unsigned int oct;
    unsigned int pitch; 
} pitchmap;

class DarmsInput: public FileInputStream
{
public:
    // constructors and destructors
    DarmsInput( Doc *doc, std::string filename );
    virtual ~DarmsInput();
    
    virtual bool ImportFile( );
    virtual bool ImportString(std::string data);
    
private:
    int do_Note(int pos, const char* data, bool rest);
    int do_globalSpec(int pos, const char* data);
    int do_Clef(int pos, const char* data);
    int parseMeter(int pos, const char* data);
    void UnrollKeysig(int quantity, char alter);
    
public:
    
private:
    std::string m_filename;

	Staff *m_staff;
    Measure *m_measure;
	Layer *m_layer;
    
    Tie *m_current_tie;
    
    unsigned int m_clef_offset;
    bool m_antique_notation; // support square notation
    
    static pitchmap PitchMap[];
};

} // namespace vrv

#endif // __VRV_IODARMS_H__
