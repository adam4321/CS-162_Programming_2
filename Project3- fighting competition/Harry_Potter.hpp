/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
** Description:    Header file for the Harry Potter derived class 
*********************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"

class Harry_Potter : public Character
{
private:
    int timesKilled = 0;
    
public:
    Harry_Potter();
    int attack() override;
    void defense(int attack, bool isMedusa) override;
};
#endif