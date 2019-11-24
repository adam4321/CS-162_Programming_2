/************************************************************************
** Program name:   Search Sort Lab
** Author:         Adam Wright
** Date:           5/21/2019
** Description:    Header file for the 3 algorithms to be tested
************************************************************************/

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


string simpleSearch(int inputArr[], int targetNum, int size);
void selectionSort(int inputArr[], int size);
string binarySearch(int inputArr[], int targetNum, int size);

#endif