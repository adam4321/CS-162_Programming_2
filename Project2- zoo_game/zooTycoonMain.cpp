/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    A game that allows the user to create their own
**                 virtual zoo. It can be run by typing zooTycoon 
**                 on the command line and following the prompts.
*********************************************************************/

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

bool requireNumbers(string menuInputTest);


int main()
{
    // Wrap the program in a do while loop to allow restarting
	bool restart = true;

	do
    {
        int mainMenuChoice = 0;
	    string menuInputTest;
        bool onlyNumbers = false;

        cout << endl << endl;
        cout << endl << endl;
        cout << "     Welcome to the Zoo Tycoon";
        cout << endl << endl;
	    cout << "                ***        " << endl;
	    cout << "            ***********         " << endl;
	    cout << "      ***********************   " << endl;
        cout << endl << endl;
        cout << "You have $100,000 to begin a Zoo business with.";
        cout << endl << endl;
        cout << "You will choose either one or two of each of" << endl;
        cout << "the following animals to start the first day with.";
        cout << endl << endl;
        cout << endl << endl;


		// While loop to validate user input of only 1 or 2 
		while (onlyNumbers == false || mainMenuChoice != 1 && mainMenuChoice != 2)
		{
			cout << "Press 1 to Play the Game" << endl;
			cout << "Press 2 to Exit";
			cout << endl << endl;
			cin >> menuInputTest;
			onlyNumbers = requireNumbers(menuInputTest);
			mainMenuChoice = atoi(menuInputTest.c_str());
			cout << endl;
		}

		// Request to quit by choosing 2 on menu
		if (mainMenuChoice == 2)
		{
			cout << "Zoo Tycoon quitting - Goodbye!";
			cout << endl << endl;
			return 0;
		}

		// Play the game
		else
		{
			// Create an instance of the Zoo class
            Zoo zooInstance;

            // Call the Zoo member function that starts the game
            zooInstance.startGame();
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
