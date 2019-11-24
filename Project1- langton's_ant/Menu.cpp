/*********************************************************************
** Program name:   Langton's Ant
** Author:         Adam Wright
** Date:           4/8/2019
** Description:    Class that implements the program's menu
*********************************************************************/

#include "Menu.hpp"

/*********************************************************************
** Description:   Default constructor that initializes the menu to
**                prepare for values to be entered
*********************************************************************/
Menu::Menu()
{
	int menuChoice = 0;
	int sizeX = 0;
	int sizeY = 0;
	int numSteps = 0;
	int startRow = 0;
	int startCol = 0;
	bool restart = false;
	
	// Prompt the user
	cout << endl << "Welcome to a simulation of Langton's Ant";
	cout << endl << endl;
	cout << "Menu:" << endl << endl;
	cout << "Press 1 to automatically place the ant" << endl;
	cout << "Press 2 to manually place the ant" << endl;
	cout << "Press 3 to quit" << endl << endl;

	// Take in user input of integer 1 or 2 or 3
	cin >> menuChoice;
	cout << endl;

	// While loop to validate user input of only 1 or 2 or 3
	while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please enter either 1 or 2 or 3 " << endl << endl;
		cin >> menuChoice;
		cout << endl;
	}

	// Request to quit by choosing 2 on menu
	if (menuChoice == 3)
	{
		cout << "Langton's Ant quitting - Goodbye!" << endl << endl;
		_Exit(0);
	}

	// Request to start Langton's Ant by choosing 1 or 2 on menu
	if (menuChoice == 2 || menuChoice == 1)
	{
		cout << "Please enter the following values to begin the simulation:";
		cout << endl << endl;

		// Prompt the user for the number of rows
		cout << "How many rows should the board have?" << endl;
		cout << "Please enter a value between 2 and 40";
		cout << endl << endl;
		cin >> sizeX;
		this->sizeX = sizeX;
		cout << endl;

		while (sizeX < 2 || sizeX > 40)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter a value between 2 and 40" << endl << endl;
			cin >> sizeX;
			this->sizeX = sizeX;
			cout << endl;
		}

		// Prompt the user for the number of columns
		cout << "How many columns should the board have?" << endl;
		cout << "Please enter a value between 2 and 40";
		cout << endl << endl;
		cin >> sizeY;
		this->sizeY = sizeY;
		cout << endl;

		while (sizeY < 2 || sizeY > 40)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter a value between 2 and 40" << endl << endl;
			cin >> sizeY;
			this->sizeY = sizeY;
			cout << endl;
		}

		// Prompt the user for the number of steps
		cout << "How many steps should the ant take?" << endl;
		cout << "Please enter a value between 1 and 20,000";
		cout << endl << endl;
		cin >> numSteps;
		this->numSteps = numSteps;
		cout << endl;

		while (numSteps < 1 || numSteps > 20000)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter a value between 1 and 20,000";
			cout << endl << endl;
			cin >> numSteps;
			this->numSteps = numSteps;
			cout << endl;
		}

		// Block that executes the automatically placed ant
		// Inspired by cplusplus.com/reference/cstdlib/rand/
		if (menuChoice == 1)
		{
			srand(time(NULL));

			startRow = rand() % sizeX;
			startCol = rand() % sizeY;
			this->startRow = startRow;
			this->startCol = startCol;
		}
		else
		{
			// Prompt for the ant's manual starting x value
			cout << "Which row should the ant start on?" << endl;
			cout << "Please enter a value between 1 and " << sizeX;
			cout << endl << endl;
			cin >> startRow;
			this->startRow = startRow - 1;
			cout << endl;

			while (startRow < 1 || startRow > sizeX)
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Please enter a value between 1 and " << sizeX;
				cout << endl << endl;
				cin >> startRow;
				this->startRow = startRow - 1;
				cout << endl;
			}

			// Prompt for the ant's manual starting y value
			cout << "What column should the ant start on?" << endl;
			cout << "Please enter a value between 1 and " << sizeY;
			cout << endl << endl;
			cin >> startCol;
			this->startCol = startCol - 1;
			cout << endl;

			while (startCol < 1 || startCol > sizeY)
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Please enter a value between 1 and " << sizeY;
				cout << endl << endl;
				cin >> startCol;
				this->startCol = startCol - 1;
				cout << endl;
			}
		}
	}
}

/*********************************************************************
** Description:   Second menu for after the simulation runs. It returns
**                the menu choice of 1 or 2 to choose whether to quit
**                or play again.
*********************************************************************/
int Menu::endMenu()
{
	cout << endl << "The simulation has completed" << endl << endl;
	cout << "Menu:" << endl << endl;
	cout << "Press 1 to play again" << endl;
	cout << "Press 2 to quit" << endl << endl;

	// Take in user input of either integer 1 or 2
	cin >> menuChoice;
	cout << endl;
    
	while (menuChoice != 1 && menuChoice != 2)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please enter either 1 or 2 " << endl << endl;
		cin >> menuChoice;
		cout << endl;
	}

	// Request to quit by choosing 2 on menu
	if (menuChoice == 2)
	{
		cout << "Langton's Ant quitting - Goodbye!" << endl << endl;
		_Exit(0);
	}

	// Request to start Langton's Ant by choosing 1 on menu
	if (menuChoice == 1)
	{
		this->restart = true;
	}
}

/*********************************************************************
** Description:   Getter functions for the private menu variables.
*********************************************************************/
int Menu::getSizeX()
{
	return sizeX;
}

int Menu::getSizeY()
{
	return sizeY;
}

int Menu::getNumSteps()
{
	return numSteps;
}

int Menu::getStartRow()
{
	return startRow;
}

int Menu::getStartCol()
{
	return startCol;
}

bool Menu::getRestart() 
{
	return restart;
}