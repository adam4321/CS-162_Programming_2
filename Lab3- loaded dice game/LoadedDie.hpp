/*********************************************************************
** Program name:   War Game
** Author:         Adam Wright
** Date:           4/17/2019
** Description:    Header file for the Loaded Die class
*********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"
#include "Game.hpp"

class LoadedDie : public Die
{
public:
	LoadedDie();
	LoadedDie(int sides);
	int roll();
};
#endif