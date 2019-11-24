/*********************************************************************
** Program name:   Three Recursive Functions
** Author:         Adam Wright
** Date:           4/30/2019
** Description:    Header file for the recursive functions file
*********************************************************************/

#ifndef RECURSIVEFUNCTIONS_HPP
#define RECURSIVEFUNCTION_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool requireNumbers(string menuInputTest);
void reverseString(string input);
int sumArray(int *numbers, int size);
int triangularNumber(int input);

#endif