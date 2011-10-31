/*
 *  Sam's Infinite Friends
 *
 *  If I do this right, it'll print a grid. WRITE MORE LATER
 *
 *
 *
 *
 */
#include <iostream>
#include "Magick++.h"
#include "argFunctions.h"
#include "numberFunctions.h"
#include "EuclideanLine.h"
#include "gcdCalculation.h"
#include "personInGrid.h"
#include "friendGrid.h"

int main (int argc, const char * argv[])
{

    
    
    friendGrid myGrid = friendGrid();
    Magick::Image prettyPrinted = myGrid.prettyPrint();
    prettyPrinted.magick("png");
    prettyPrinted.write("Output");
    return 0;
}