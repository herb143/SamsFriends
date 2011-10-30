/*
 *  personInGrid.h
 *  SamsFriends
 *
 *  Represents one person surrounding Sam, or Sam himself.
 */

#ifndef SamsFriends_personInGrid_h
#define SamsFriends_personInGrid_h

class personInGrid
{
private:
    int m_nX; // Their position in the grid relative to Sam.
    int m_nY;
    
    int m_nSlopeToSamNum; // The numerator and denomenator of 
    int m_nSlopeToSamDen;
    
    bool m_bCanSeeSam; // Can they see Sam?
    
public:
    personInGrid();
};

#endif
