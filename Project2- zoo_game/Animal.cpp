/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    Base class that implements an Animal
*********************************************************************/

#include "Animal.hpp"

/*********************************************************************
** Description:   Default constructor that initializes an Animal
*********************************************************************/
Animal::Animal()
{
    setAge(0);
}

/*********************************************************************
** Description:   Animal constructor that sets an Animals age
*********************************************************************/
Animal::Animal(int ageInput)
{
    setAge(ageInput);
}

/*********************************************************************
** Description:   Getter and setter methods for Animal
*********************************************************************/
void Animal::setAge(int ageInput)
{
    age = ageInput;
}

int Animal::getAge()
{
    return age;
}

int Animal::getCost()
{
    return cost;
}

int Animal::getNumBabies()
{
    return numBabies;
}

int Animal::getBaseFoodCost()
{
    return baseFoodCost;
}

double Animal::getPayoff()
{
    return payoff;
}