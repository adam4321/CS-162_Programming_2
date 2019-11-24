/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    Derived class of Animal that implements a Turtle
*********************************************************************/

#include "Turtle.hpp"
#include "Animal.hpp"

/*********************************************************************
** Description:   Default constructor that initializes a Turtle
*********************************************************************/
Turtle::Turtle() : Animal(0)
{
	cost = 100;
	numBabies = 10;
	baseFoodCost =  BASE_FOOD_COST / 2;
    payoff = 0.05 * 100;
}

/*********************************************************************
** Description:   Default constructor that initializes a Turtle
*********************************************************************/
Turtle::Turtle(int ageInput) : Animal(ageInput)
{
	cost = 100;
	numBabies = 10;
	baseFoodCost = BASE_FOOD_COST / 2;
    payoff = 0.05 * 100;
}