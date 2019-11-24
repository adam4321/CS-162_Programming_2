/*********************************************************************
** Program name:   War Game
** Author:         Adam Wright
** Date:           4/17/2019
** Description:    Derived class of Die that implements the Loaded Die
*********************************************************************/

#include "LoadedDie.hpp"
#include "Die.hpp"
#include "Game.hpp"

/*********************************************************************
** Description:   Default constructor that initializes the loaded die
**                using the base Die class 
*********************************************************************/
LoadedDie::LoadedDie() : Die() {}

/*********************************************************************
** Description:   Constructor function that initializes the die with
**                using the base Die class and passes in the number of
**                sides for the die as the argument
*********************************************************************/
LoadedDie::LoadedDie(int sides) : Die(sides) {}

/*********************************************************************
** Description:   Function that implements the Loaded Die's rolling
**                behavior. It will always roll higher than a random 
**                average
*********************************************************************/
int LoadedDie::roll()
{
	rollSide = rand() % numDieSides + 3;

	if (rollSide > numDieSides)
	{
		rollSide = numDieSides;
	}

	return rollSide;
}