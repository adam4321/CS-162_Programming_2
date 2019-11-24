/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    Derived class of Animal that implements a Tiger
*********************************************************************/

#include "Tiger.hpp"
#include "Animal.hpp"

/*********************************************************************
** Description:   Default constructor that initializes a Tiger
*********************************************************************/
Tiger::Tiger() : Animal(0)
{
	cost = 10000;
	numBabies = 1;
	baseFoodCost = 5 * BASE_FOOD_COST;
    payoff = 0.2 * 10000;
}

/*********************************************************************
** Description:   Tiger constructor that initializes a Tiger 
*********************************************************************/
Tiger::Tiger(int ageInput) : Animal(ageInput)
{
	cost = 10000;
	numBabies = 1;
	baseFoodCost = 5 * BASE_FOOD_COST;
    payoff = 0.2 * 10000;
}

