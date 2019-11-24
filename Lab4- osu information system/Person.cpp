/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    File that implements the Person class
*********************************************************************/

#include "Person.hpp"

/*********************************************************************
** Description:    Constructor for the Person class that takes in a 
**                 string which is the person's name and an int for 
**                 the person's age
*********************************************************************/
Person::Person(string inputName, int inputAge)
{
    name = inputName;
    age = inputAge;
}

/*********************************************************************
** Description:    Function that prints the person's name
*********************************************************************/
void Person::printName()
{
    cout << name;
}

/*********************************************************************
** Description:    Function that prints the person's age
*********************************************************************/
void Person::printAge()
{
    cout << age;
}

/*********************************************************************
** Description:    Function that is implemented in the derived student
**                 class to print a student's gpa
*********************************************************************/
void Person::printGpa() {}

/*********************************************************************
** Description:    Function that is implemented in the derived 
**                 instructor class to print the instructor's rating
*********************************************************************/
void Person::printRating() {}

/*********************************************************************
** Description:    Function that is implemented differently in each 
**                 derived class to print a query about each subclass
*********************************************************************/
void Person::do_work() {}
