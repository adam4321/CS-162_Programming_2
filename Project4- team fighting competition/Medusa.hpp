/*********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
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