/*********************************************************************
** Program name:   Langton's Ant
** Author:         Adam Wright
** Date:           4/8/2019
** Description:    Header file for the Ant class
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Ant.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Ant
{
private: 
	int sizeX;
	int sizeY;
	int numSteps;
	int startRow;
	int startCol;
	int antX;
	int antY;
	int direction;
	int pointUp;
	int pointRight;
	int pointDown;
	int pointLeft;
	int boardSize;
public:
	Ant(Menu menu);
};
#endif
