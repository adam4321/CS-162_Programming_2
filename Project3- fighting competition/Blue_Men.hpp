/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
** Description:    Header file for the Blue_Men derived class 
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class Blue_Men : public Character
{
public:
    Blue_Men();
    int attack() override;
    void defense(int attack, bool inputMedusa) override;
};

#endif