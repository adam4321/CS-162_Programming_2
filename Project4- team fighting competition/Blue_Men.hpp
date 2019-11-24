/*********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
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