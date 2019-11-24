/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    Header file for the Animal class
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

const int BASE_FOOD_COST = 10;


class Animal
{
protected:
    int age;
    int cost;
    int numBabies;
    int baseFoodCost;
    double payoff;

public:
    Animal();
    Animal(int);
    virtual void setAge(int);
    virtual int getAge();
    virtual int getCost();
    virtual int getNumBabies();
    virtual int getBaseFoodCost();
    virtual double getPayoff();
};
#endif