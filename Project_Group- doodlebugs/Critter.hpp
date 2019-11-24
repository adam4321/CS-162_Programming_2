/***********************************************************************
** Program name:   Predator Prey simulation
** Author:         Group 16
** Date:           5/3/2019
** Description:    Header file for the Critter base class
***********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <stdlib.h>

class Critter
{
protected:
    int x;
    int y;
    int stepsSurvived;
    char symbol;
public:
    Critter() {};
    Critter(int inputX, int inputY) {};
    virtual ~Critter() = 0;
    char getSymbol();
    virtual int getStarved() = 0;                                    
    virtual void move(Critter ***&inputArray) = 0;
    virtual void breed(Critter ***&inputArray) = 0;
};
#endif