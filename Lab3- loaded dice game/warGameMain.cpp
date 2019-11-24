/**********************************************************************
** Program name:   War Game
** Author:         Adam Wright
** Date:           4/17/2019
** Description:    Game that is a simplified version of War using dice            
**********************************************************************/

#include "LoadedDie.hpp"
#include "Die.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************************************
** Description:   Function to make sure that only integers are being
**                passed and not characters or periods or spaces. It takes
**                a string as input and returns true if it only contains
**                the numbers 0 - 9. The idea came from
**                Ferdinando Randisi with the second most
**                popular solution on this stack overflow thread.
**                https://stackoverflow.com/questions/2844817/
**                how-do-i-check-if-a-c-string-is-an-int
*********************************************************************/
bool requireNumbers(string menuInputTest)
{
	return menuInputTest.find_first_not_of("0123456789") == string::npos;
}


int main()
{
	// Wrap the program in a do while loop to allow restarting
	bool restart = true;

	do
	{
		int mainMenuChoice = 0;
		string menuInputTest;
		bool onlyNumbers = false;

		// Prompt the user and ask whether they want to play or quit
		cout << endl << endl;
		cout << "Welcome to the Dice rolling War Game" << endl;
		cout << endl << endl;
		cout << "                ***        " << endl;
		cout << "            ***********         " << endl;
		cout << "      ***********************   " << endl;
		cout << endl << endl;
		cout << "It is a 2 player take on the card game War";
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
			cout << "Dice rolling War Game quitting - Goodbye!";
			cout << endl << endl;
			return 0;
		}

		// Play the game
		else
		{
			// Create an instance of the game
			Game game;
            
			// Call the calculate and print method
			game.calculateAndPrint();

			// Call the after game menu method
			restart = game.endMenu();
		}

	} while (restart == true);

	return 0;
}