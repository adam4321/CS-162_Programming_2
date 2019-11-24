/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    Header file for the Zoo class
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;


class Zoo
{
protected:
  double moneyInBank;
  int menuChoice;
  int endGame;
  int currentDay;
  int numTigers;
  int numPenguins;
  int numTurtles;
  int tigerArrSize;
  int penguinArrSize;
  int turtleArrSize;
  Tiger* tigerArr;
  Penguin* penguinArr;
  Turtle* turtleArr;

public:
    Zoo();
    ~Zoo();
    void startGame();
    bool requireOnlyNumbers(string menuInputTest);
    bool requireFloatNumbers(string menuInputTest);
    int dayEndMenu();
    void addTiger(int input);
	void addPenguin(int input);
    void addTurtle(int input);
    void kill();
    void zooBoom();
    void baby();
};
#endif