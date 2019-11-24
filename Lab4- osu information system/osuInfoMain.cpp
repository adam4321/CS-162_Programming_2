/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    A program that represents the OSU information system
**                 by offering a menu that allows the user to print
**                 the list of buildings, students and instructors.
**                 The program can be run by typing osuInfo on the 
**                 command line and then following the prompts.
*********************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "University.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool requireNumbers(string menuInputTest);


int main()
{
    // Seed the random function
    srand(time(NULL));

    // Create an instance of the University class
    University uni;

    // Do while loop that runs until the user quits
    bool restart = true;

	do
    {
        int menuChoice = 0;
	    string menuInputTest;
        bool onlyNumbers = false;

        cout << endl << endl;
        cout << endl << endl;
        cout << "*****************************************" << endl;
        cout << "* Welcome to the OSU Information System *" << endl;
        cout << "*****************************************";
        cout << endl << endl;
        cout << "Please choose from the following menu options";
        cout << endl << endl;


		// While loop to validate user input of only 1 2 3 or 4  
		while (onlyNumbers == false || menuChoice != 1 && menuChoice != 2
                                    && menuChoice != 3 && menuChoice != 4)
		{
			cout << "Press 1 to Print the building information" << endl;
            cout << "Press 2 to print everyone at the university" << endl;
			cout << "Press 3 to find out how much someone works" << endl;
			cout << "Press 4 to Exit";
			cout << endl << endl;
			cin >> menuInputTest;
			onlyNumbers = requireNumbers(menuInputTest);
			menuChoice = atoi(menuInputTest.c_str());
			cout << endl;
		}

		// Request to quit by choosing 2 on menu
		if (menuChoice == 4)
		{
			cout << "OSU Information System quitting - Goodbye!";
			cout << endl << endl;
			return 0;
		}

        // Prints information about all buildings
        if (menuChoice == 1)
        {
            uni.printBuildings();
        }

        // Prints information about everybody at the university
        if (menuChoice == 2)
        {
            uni.printPeople();
        }

        // Print the list of people then print the do_work menu from university
        if (menuChoice == 3)
        {
            uni.printPeople();
            cout << endl << endl;
            uni.chooseWorker();
        }

    } while (restart == true);
}

/*********************************************************************
** Description:   Function to make sure that only integers are being
**                passed and not characters or periods or spaces. It takes
**                a string as input and returns true if it only contains
**                the numbers 0 - 9.
*********************************************************************/
bool requireNumbers(string menuInputTest)
{
	return menuInputTest.find_first_not_of("0123456789") == string::npos;
}    
