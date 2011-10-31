/*
 *  friendGrid.h
 *  SamsFriends
 *
 *  Will hold all of the friend values.
 */

#ifndef SamsFriends_friendGrid_h
#define SamsFriends_friendGrid_h

class friendGrid
{
private:
    int m_nWidth; // The width and length of the grid.
    int m_nLength;
    int m_nOriginX;
    int m_nOriginY;
    
    inline int getGridX(int nArrayX);
    inline int getGridY(int nArrayY);
    
    personInGrid ***m_personArray;    
public:
    friendGrid(); // Constructor with arraysize.
    ~friendGrid(); // Destructor.
    
    Magick::Image prettyPrint();
};

#endif
