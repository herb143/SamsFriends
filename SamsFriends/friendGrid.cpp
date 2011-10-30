/*
 *  friendGrid.cpp
 *  SamsFriends
 *
 *  Will hold all of the friend values.
 */

#include <iostream>
#include "numberFunctions.h"
#include "EuclideanLine.h"
#include "gcdCalculation.h"
#include "personInGrid.h"
#include "friendGrid.h"


friendGrid::friendGrid()
{
    
    m_nWidth = 50;
    m_nLength = 50;

 //   personInGrid personArray[25][25] = { personInGrid(0, 0) };
    m_nOriginX = m_nWidth / 2; // Dropping the fraction, this works.
    m_nOriginY = m_nLength / 2;
    
    
    
    m_personArray = new personInGrid**[m_nLength + 1]; // Create a dynamic multidimensional array.
    
    for (int iii = 0; iii < m_nLength + 1; iii++)
    {
        m_personArray[iii] = new personInGrid*[m_nWidth + 1];
    }
    
    for (int iii = 0; iii <= m_nLength; iii++) // For every row...
    {
        for (int bbb = 0; bbb <= m_nWidth; bbb++) // For every item in that row...
        {
            m_personArray[iii][bbb] = new personInGrid(getGridX(bbb), getGridY(iii));
        }
    }

    
    
}

inline int friendGrid::getGridX(int nArrayX)
{
    return nArrayX - m_nOriginX;
}

inline int friendGrid::getGridY(int nArrayY)
{
    return nArrayY - m_nOriginY;
}

friendGrid::~friendGrid() // Destructor.
{
    for (int iii = 0; iii < m_nLength; iii++) // Scroll through the array's first dimension.
    {
        delete[] m_personArray[iii];
        m_personArray[iii] = 0; // Set it to null, just in case.
    }
    delete[] m_personArray; // Reallocate the memory.
    m_personArray = 0; // Set the array to null, just in case.
}

void friendGrid::prettyPrint()
{
    for (int iii = 0; iii < m_nLength; iii++) // For every row...
    {
        for (int bbb = 0; bbb < m_nWidth; bbb++) // For every item in that row...
        {
          /*  if (((*m_personArray[iii][bbb]).getX() == -1) && ((*m_personArray[iii][bbb]).getY() == -1))
            {
                std::cout << "WE GOT IT" << std::endl;
            } */
            if ((*m_personArray[iii][bbb]).getX() == 0 && (*m_personArray[iii][bbb]).getY() == 0) // If it's sam...
            {
                std::cout << "\033[1;42mS\033[0m";
            }
            else if ((*m_personArray[iii][bbb]).canSeeSam()) // If they can see Sam...
            {
                std::cout << "\033[1;42m \033[0m";
            }
            else
            {
                std::cout << "\033[1;44m \033[0m";
            }
            if (bbb == m_nWidth - 1) // If it's last in the row...
            {
                std::cout << std::endl;
            }
        }
    }
}