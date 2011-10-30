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
#include <stdlib.h>
#include "argFunctions.h"
#include "numberFunctions.h"
#include "EuclideanLine.h"
#include "gcdCalculation.h"
#include "slopeFraction.h"
#include "personInGrid.h"
#include "friendGrid.h"

int main (int argc, const char * argv[])
{

    friendGrid myGrid = friendGrid();
    myGrid.prettyPrint();
    
  //  personInGrid myPerson = personInGrid(20, 77);
    return 0;
}

