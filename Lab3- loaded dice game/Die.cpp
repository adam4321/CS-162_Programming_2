/*********************************************************************
** Program name:   War Game
** Author:         Adam Wright
** Date:           4/17/2019
** Description:    Base class that implements the Unloaded Die          
*********************************************************************/

#include "LoadedDie.hpp"
#include "Die.hpp"
#include "Game.hpp"

/*********************************************************************
** Description:   Default constructor that initializes the die to
**                an incorrect value if no arguments are passed
*********************************************************************/
Die::Die()
{
	numDieSides = -1;
}

/*********************************************************************
** Description:   Constructor function that initializes the die with
**                the number of sides passed in as the argument
*********************************************************************/
Die::Die(int sides)
{
	numDieSides = sides;
}

/*********************************************************************
** Description:   Function that implements the Unloaded Die's rolling
**                behavior. It will always roll a random average score
*********************************************************************/
int Die::roll()
{
	rollSide = rand() % numDieSides + 1;

	return rollSide;
}