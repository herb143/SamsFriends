/*
 *  personInGrid.cpp
 *  SamsFriends
 *
 *  Represents one person surrounding Sam, or Sam himself.
 */

#include <iostream>
#include "numberFunctions.h"
#include "EuclideanLine.h"
#include "gcdCalculation.h"
#include "slopeFraction.h"
#include "personInGrid.h"

personInGrid::personInGrid() // Default constructor. WE DON'T WANT THIS.
{
    std::cerr << "Error: Grid point constructed without proper values!" << std::endl;
    exit(1);
}

personInGrid::personInGrid(int nX, int nY)
{
    m_nX = nX;
    m_nY = nY;
    
    m_theSlope = slopeFraction(0, m_nX, 0, m_nY); // The slope between them and Sam.
    m_bCanSeeSam = m_theSlope.isSimplestForm(); // If the fraction is in its simplest form, then we can see sam.
}