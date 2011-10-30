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
    
    slopeFraction m_theSlope;
    bool m_bCanSeeSam; // Can they see Sam?
    
public:
    personInGrid(); // Default constructor. WE DON'T WANT THIS.
    personInGrid(int nX, int nY);
    
    bool canSeeSam() { return m_bCanSeeSam; }
    slopeFraction getSlope() { return m_theSlope; }
    int getX() { return m_nX; }
    int getY() { return m_nY; }
};

#endif
