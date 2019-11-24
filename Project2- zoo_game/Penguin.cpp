/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    Derived class of Animal that implements a Penguin
*********************************************************************/

#include "Penguin.hpp"
#include "Animal.hpp"

/*********************************************************************
** Description:   Default constructor that initializes a Penguin
*********************************************************************/
Penguin::Penguin() : Animal(0)
{
	cost = 1000;
	numBabies = 5;
	baseFoodCost =  BASE_FOOD_COST;
    payoff = 0.1 * 1000;
}

/*********************************************************************
** Description:   Penguin constructor that initializes a Penguin
*********************************************************************/
Penguin::Penguin(int ageInput) : Animal(ageInput)
{
	cost = 1000;
	numBabies = 5;
	baseFoodCost = BASE_FOOD_COST;
    payoff = 0.1 * 1000;
}
