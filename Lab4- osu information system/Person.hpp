/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    Header file for the Person class
*********************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Person
{
protected:
    string name;
    int age;
public:
    Person(string inputName, int inputAge);
    virtual void printName();
    virtual void printAge();
    virtual void printRating();
    virtual void printGpa();
    virtual void do_work();
};
#endif