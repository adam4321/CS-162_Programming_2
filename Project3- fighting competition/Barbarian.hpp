/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
** Description:    Header file for the Barbarian derived class 
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character
{
public:
    Barbarian();
    int attack() override;
    void defense(int attack, bool inputMedusa) override;
};
#endif