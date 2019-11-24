/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
** Description:    Header file for the Vampire derived class 
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character
{
public:
    Vampire();
    int attack() override;
    void defense(int attack, bool inputMedusa) override;
};
#endif