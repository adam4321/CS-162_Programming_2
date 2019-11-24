/*********************************************************************
** Program name:   Langton's Ant
** Author:         Adam Wright
** Date:           4/8/2019
** Description:    Header file for the Menu class
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "Menu.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

class Menu
{
private:
	int menuChoice;
	int sizeX;
	int sizeY;
	int numSteps;
	int startRow;
	int startCol;
	bool restart;
public:
	Menu();
	int endMenu();
	int getSizeX();
	int getSizeY();
	int getNumSteps();
	int getStartRow();
	int getStartCol();
	bool getRestart();
};
#endif