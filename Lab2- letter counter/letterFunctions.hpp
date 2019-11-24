/*********************************************************************
** Program name:    Letter Counter
** Author:          Adam Wright
** Date:            4-12-2019
** Description:     Header file for the count letters and output 
**                  letters functions 
*********************************************************************/

#ifndef LETTERFUNCTIONS_HPP
#define LETTERFUNCTIONS_HPP

#include "letterFunctions.hpp"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

void count_letters(ifstream &infile, int *occurrenceArray);
void output_letters(ofstream &outfile, int *occurrenceArray);

#endif