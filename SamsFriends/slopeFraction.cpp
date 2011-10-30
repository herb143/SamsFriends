/*
 *  slopeFraction.cpp
 *  SamsFriends
 *
 *  The slope of a line between two points.
 */

#include <iostream>
#include "numberFunctions.h"
#include "EuclideanLine.h"
#include "gcdCalculation.h"
#include "personInGrid.h"
#include "slopeFraction.h"

slopeFraction::slopeFraction() // Default constructor -- WE DON'T WANT THIS
{
    std::cerr << "Error: Slope fraction constructed without proper values!" << std::endl;
    exit(1);
}

slopeFraction::slopeFraction(int nAX, int nBX, int nAY, int nBY)
{
    m_nAX = nAX; // Set all of the internal values.
    m_nBX = nBX;
    m_nAY = nAY;
    m_nBY = nBY;
    
    int nTempNumerator = m_nAY - m_nBY; // Temp fraction values.
    int nTempDenominator = m_nAX - m_nBX;
    
    if (nTempDenominator == 0) // If we have a 0 denomenator...
    {
        m_bInfinite = true; // It is infinite.
        m_bSimplestForm = true; // You can't simplify that.
    }
    else if (nTempNumerator == 0)
    {
        m_bInfinite = false; // It's not infinite.
        nTempDenominator = 0; // And our denominator is 0;
        m_bSimplestForm = true; // And we cannot simplify.
        
    }
    else if (nTempNumerator < 0 && nTempDenominator < 0) // If both are negative, make them positive.
    {
        nTempNumerator = nTempNumerator * -1;
        nTempDenominator = nTempDenominator * -1;
        m_bInfinite = false; // It's not infinite.
        
        int theGCD = gcdCalculation(nTempNumerator, nTempDenominator).getGCD();
        
        if (theGCD != 1) // If we can simplifty...
        {
            m_bSimplestForm = false;
        }
        else
        {
            m_bSimplestForm = true;
        }
        
    }
    else if (nTempNumerator > 0 && nTempDenominator < 0) // If negative denominator and positive numerator, move the negative sign.
    {
        nTempNumerator = nTempNumerator * -1;
        nTempDenominator = nTempDenominator * -1;
        m_bInfinite = false; // It's not infinite.
        
        int theGCD = gcdCalculation(nTempNumerator, nTempDenominator).getGCD();
        
        if (theGCD != 1) // If we can simplifty...
        {
            m_bSimplestForm = false;
        }
        else
        {
            m_bSimplestForm = true;
        }
        
    }
    else if (nTempNumerator > 0 && nTempDenominator > 0) // If both positive, do nothing.
    {
        m_bInfinite = false; // It's not infinite.
        
        int theGCD = gcdCalculation(nTempNumerator, nTempDenominator).getGCD();
        
        if (theGCD != 1) // If we can simplifty...
        {
            m_bSimplestForm = false;
        }
        else
        {
            m_bSimplestForm = true;
        }
        
    }
    
    m_nNumeratorUnsimp = nTempNumerator;
    m_nDenominatorUnsimp = nTempDenominator;
    
    if (m_bSimplestForm) // If you can't simplify.
    {
        m_nDenominatorSimp = m_nDenominatorUnsimp;
        m_nNumeratorSimp = m_nNumeratorUnsimp;
    }
    else // If you can...
    {
        int theGCD = gcdCalculation(nTempNumerator, nTempDenominator).getGCD();
        m_nNumeratorSimp = m_nNumeratorUnsimp / theGCD;
        m_nDenominatorSimp = m_nDenominatorUnsimp / theGCD;
    }
    
}