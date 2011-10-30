/*
 *  slopeFraction.h
 *  SamsFriends
 *
 *  The slope of a line between two points.
 */

#ifndef SamsFriends_slopeFraction_h
#define SamsFriends_slopeFraction_h

class slopeFraction
{
private:
    int m_nAX; // The x and y values of the points.
    int m_nBX;
    int m_nAY;
    int m_nBY;
    
    int m_nNumeratorUnsimp; // The unsimplified numerator and denominator.
    int m_nDenominatorUnsimp;
    
    int m_nNumeratorSimp; // The simplified numerator and denominator.
    int m_nDenominatorSimp;
    
    bool m_bSimplestForm; // Is it in simplest form?
    bool m_bInfinite; // Is it infinite?
    
public:
    slopeFraction(); // Default constructor returns an error.
    slopeFraction(int nAX, int nBX, int nAY, int nBY); // The constructor we want.
    
    // Getters.
    int getFirstX() { return m_nAX; }
    int getFirstY() { return m_nAY; }
    int getSecondX() { return m_nBX; }
    int getSecondY() { return m_nBY; }
    int getDenomUnsimp() { return m_nDenominatorUnsimp; }
    int getNumUnsimp() { return m_nNumeratorUnsimp; }
    int getDenomSimp() { return m_nDenominatorSimp; }
    int getNumSimp() { return m_nNumeratorSimp; }
    bool isSimplestForm() { return m_bSimplestForm; }
    bool isInfinite() { return m_bInfinite; }
    
    
};

#endif
