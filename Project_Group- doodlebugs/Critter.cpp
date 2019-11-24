/***********************************************************************
** Program name:   Predator Prey simulation
** Author:         Group 16
** Date:           5/3/2019
** Description:    File that implements the Critter base class
***********************************************************************/

#include "Critter.hpp"

/*********************************************************************
** Description:   Destructor for the Critter base class
*********************************************************************/
Critter::~Critter() {}

/*********************************************************************
** Description:   Getter for the Critter base class
*********************************************************************/
char Critter::getSymbol()
{
    return symbol;
}
