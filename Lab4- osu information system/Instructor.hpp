/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    Header file for the Instructor class
*********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Instructor : public Person
{
protected:
    double rating;
public:
    Instructor(string inputName, int inputAge, double inputRating);
    void printRating();
    void do_work();
};
#endif