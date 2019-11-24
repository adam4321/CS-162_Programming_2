/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    File that implements the Instructor class
*********************************************************************/

#include "Instructor.hpp"

/*********************************************************************
** Description:    Constructor function for the Instructor class that
**                 takes in a string for the instructor's name and 
**                 and int for their age and a double for their rating.
**                 The name and age are implemented in the base case.
*********************************************************************/
Instructor::Instructor(string inputName, int inputAge, double inputRating)
                                            : Person(inputName, inputAge)
{
    rating = inputRating;
}

/*********************************************************************
** Description:    Function that prints the instructor's rating
*********************************************************************/
void Instructor::printRating()
{
    cout << rating;
}

/*********************************************************************
** Description:    Function that prints a random number that represents
**                 the amount of work that the instructor has done
*********************************************************************/
void Instructor::do_work()
{
    int amount = rand() % 20 + 30;
    
    cout << "....................................."<< endl;
    cout << "This instructor worked " << amount << " hours." << endl;
    cout << ".....................................";
}