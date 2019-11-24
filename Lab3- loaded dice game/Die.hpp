/*********************************************************************
** Program name:   War Game
** Author:         Adam Wright
** Date:           4/17/2019
** Description:    Header file for the Die class
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include "LoadedDie.hpp"
#include "Game.hpp"

class Die
{
protected:
	int numDieSides;
	int rollSide;
public:
	Die();
	Die(int sides);
	int roll();
};
#endif