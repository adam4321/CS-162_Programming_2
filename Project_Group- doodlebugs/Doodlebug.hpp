/**************************************************************************
** Program name:   Predator Prey simulation
** Author:         Group 16
** Date:           5/3/2019
** Description:    Header file for the Doodlebug class derived from critter
**************************************************************************/

#include "Critter.hpp"

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

class Doodlebug : public Critter
{
protected:
    int starve;
public:
    Doodlebug(int inputX, int inputY);
    ~Doodlebug() {};
    int getStarved();
    virtual void move(Critter ***&inputArray);
    virtual void breed(Critter ***&inputArray);
};
#endif