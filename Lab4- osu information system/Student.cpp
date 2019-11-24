/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    File that implements the Student class
*********************************************************************/

#include "Student.hpp"

/*********************************************************************
** Description:    Default constructor for the Student class which takes
**                 in a string for student's name and an int for their 
**                 age and a double for their gpa. The name and age are
**                 implemented in the base person class.
*********************************************************************/
Student::Student(string inputName, int inputAge, double inputGpa) 
                                    : Person(inputName, inputAge)
{
    gpa = inputGpa;
}

/*********************************************************************
** Description:    Function that prints the student's rating
*********************************************************************/
void Student::printGpa()
{
    cout << gpa;
}

/*********************************************************************
** Description:    Function that prints a random number that represents
**                 the amount of studying that the student has done
*********************************************************************/
void Student::do_work()
{
    int amount = rand() % 30 + 15;

    cout << "...................................."<< endl;
    cout << "This student studied " << amount << " hours." << endl;
    cout << "....................................";
}