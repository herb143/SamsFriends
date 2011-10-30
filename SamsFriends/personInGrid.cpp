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
#include "personInGrid.h"

personInGrid::personInGrid() // Default constructor. WE DON'T WANT THIS.
{
    
    std::cerr << "Error! Grid point constructed improperly!" << std::endl;
    exit(1);
}

personInGrid::personInGrid(int nX, int nY)
{
    m_nX = nX;
    m_nY = nY;
    if (m_nX == 0)
    {
        if (m_nY == 1 || m_nY == 0 || m_nY == -1)
        {
            m_bCanSeeSam = true;
        }
        else
        {
            m_bCanSeeSam = false;
        }
    }
    else if (m_nY == 0)
    {
        if (m_nX == 1 || m_nX == 0 || m_nX == -1)
        {
            m_bCanSeeSam = true;
        }
        else
        {
            m_bCanSeeSam = false;
        }
    }
    else if (gcdCalculation(nX, nY).getGCD() == 1) {
        m_bCanSeeSam = true;
    }
    else
    {
        m_bCanSeeSam = false;
    }
    
}