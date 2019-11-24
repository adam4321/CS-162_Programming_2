/*********************************************************************
** Program name:   War Game
** Author:         Adam Wright
** Date:           4/17/2019
** Description:    Header file for the Game class
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "LoadedDie.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Game
{
private:
	int numOfRounds;
	int playerOneDieType;
	int playerTwoDieType;
	int playerOneDieSides;
	int playerTwoDieSides;
	int endMenuChoice;
	bool onlyNumbers;
	string menuInputTest;
	bool requireOnlyNumbers(string menuTest);
public:
	Game();
	void calculateAndPrint();
	int endMenu();
};
#endif