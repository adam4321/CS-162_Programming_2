/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    Header file for the Student class
*********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Student : public Person
{
protected:
    double gpa;
public:
    Student(string inputName, int inputAge, double inputGpa);
    void printGpa();
    void do_work();
};
#endif