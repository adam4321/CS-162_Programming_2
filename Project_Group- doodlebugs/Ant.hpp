/***********************************************************************
** Program name:   Predator Prey simulation
** Author:         Group 16
** Date:           5/3/2019
** Description:    Header file for the Ant class derived from critter
***********************************************************************/

#include "Critter.hpp"

#ifndef ANT_HPP
#define ANT_HPP

class Ant : public Critter
{
public:
    Ant(int inputX, int inputY);
    ~Ant() {};
    virtual int getStarved() {};
    virtual void move(Critter ***&inputArray);
    virtual void breed(Critter ***&inputArray);
};
#endif