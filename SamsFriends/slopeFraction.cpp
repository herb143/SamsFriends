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
        if (nTempNumerator == 1 || nTempNumerator == -1) { m_bSimplestForm = true; } // This isn't completely correct, but it works here.
        else { m_bSimplestForm = false; }
    }
    else if (nTempNumerator == 0)
    {
        m_bInfinite = false; // It's not infinite.
        if (nTempDenominator == 1 || nTempDenominator == -1) { m_bSimplestForm = true; } // This isn't completely correct, but it works here.
        else { m_bSimplestForm = false; }
        
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
    
    if (!m_bSimplestForm && m_nNumeratorUnsimp != 0 && m_nDenominatorUnsimp != 0) // If you can simplify and it's not messing with 0's (my GCD function wasn't designed for that).
    {
        int theGCD = gcdCalculation(nTempNumerator, nTempDenominator).getGCD();
        m_nNumeratorSimp = m_nNumeratorUnsimp / theGCD;
        m_nDenominatorSimp = m_nDenominatorUnsimp / theGCD;

    }
    else // If you cannot
    {
        m_nDenominatorSimp = m_nDenominatorUnsimp;
        m_nNumeratorSimp = m_nNumeratorUnsimp;
    }
    
}