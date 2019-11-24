/***********************************************************************
** Program name:   Template Library Containers
** Author:         Adam Wright
** Date:           5/27/2019
** Description:    Console application that offers two functions for the
**                 user to test. The functions reply on using the 
**                 standard template library. The program can be run by 
**                 typing templates into the console and following the 
**                 prompts
***********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

#include "functions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool requireNumbers(string menuInputTest);


int main()
{
    // Seed the random function
    srand(time(NULL));

    int menuChoice = 0;
    string menuInputTest;
    bool onlyNumbers = false;
    int inputNumber;

    do
    {
    	// Do While loop to allow restarting 
        onlyNumbers = false;

        cout << endl << endl;
        cout << "***************************************" << endl;
        cout << "An Exploration of Template Containers" << endl;
        cout << "***************************************";
        cout << endl << endl;
        cout << "Please choose one of the options" << endl;
        cout << "from the following list";
        cout << endl << endl;

        // Print the menu each time through the loop
        onlyNumbers = false;

		while (onlyNumbers == false || 
                    menuChoice != 1 && menuChoice != 2 && menuChoice != 3)
		{
			cout << "Press 1 to Create a buffer" << endl;
            cout << "Press 2 to Create a palindrome" << endl;
            cout << "Press 3 to Exit";
 			cout << endl << endl;
			cin >> menuInputTest;
			onlyNumbers = requireNumbers(menuInputTest);
			menuChoice = atoi(menuInputTest.c_str());
            cout << endl;
        }

        // Select 1 to run buffer function
        if (menuChoice == 1)
        {
            int rounds = 0;
            int percentEnd = 0;
            int percentFront = 0;

            onlyNumbers = false;

            while (onlyNumbers == false || rounds < 1
                                        || rounds > 1000)
            {
                cout << "Please enter a number between 1 and 1,000" << endl;
                cout << "for the number of rounds that will be simulated";
                cout << endl << endl;
                cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    rounds = atoi(menuInputTest.c_str());
                cout << endl;
            }

            onlyNumbers = false;

            while (onlyNumbers == false || percentEnd < 1
                                        || percentEnd > 100)
            {
                cout << "Please enter a number between 1 and 100" << endl;
                cout << "for the percentage chance that a randomly" << endl;
                cout << "generated number will be place at the queue's end";
                cout << endl << endl;
                cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    percentEnd = atoi(menuInputTest.c_str());
                cout << endl;
            }

            onlyNumbers = false;

            while (onlyNumbers == false || percentFront < 1
                                        || percentFront > 100)
            {
                cout << "Please enter a number between 1 and 100" << endl;
                cout << "for the percentage chance that a number" << endl;
                cout << "will be removed from the queue's front";
                cout << endl << endl;
                cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    percentFront = atoi(menuInputTest.c_str());
                cout << endl;
            }

            cout << endl;
            randomBuffer(rounds, percentEnd, percentFront);
        }

        // Select 2 to run palindrome function
        if (menuChoice == 2)
        {
            string inputString;
            cout << "Please enter a string and I'll return it as a palindrome";
            cout << endl << endl;

            cin >> inputString;
            cout << endl << endl;

            // Call the function with the inputted string
            palindrome(inputString);
            cout << endl;
        }

        // Select 3 to exit
        if (menuChoice == 3)
        {
            cout << "Template Container Lab Quitting  --  Goodbye!";
            cout << endl << endl;

            return 0;
        } 

    } while (true);
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