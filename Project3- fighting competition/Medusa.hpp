/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
** Description:    Header file for the Medusa derived class 
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{
public:
    Medusa();
    int attack() override;
    void defense(int attack, bool inputMedusa) override;
};

#endif