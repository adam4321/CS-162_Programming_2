/*********************************************************************
** Program name:   War Game
** Author:         Adam Wright
** Date:           4/17/2019
** Description:    Class that implements the game
*********************************************************************/

#include "Game.hpp"
#include "LoadedDie.hpp"
#include "Die.hpp"


/*********************************************************************
** Description:   Default constructor that initializes the game 
**                and runs the user through the menu to set the values
**                for the game
*********************************************************************/

Game::Game()
{
	// Setup variables

	int numOfRounds = 0;
	int playerOneDieType = 0;
	int playerTwoDieType = 0;
	int playerOneDieSides = 0;
	int playerTwoDieSides = 0;
	bool onlyNumbers = false;
	string menuInputTest;

	// Menu to prompt the user for the values to start the game

	cout << "Please enter the following values to begin the game:";
	cout << endl << endl;

	// Prompt the user for the number of rounds

	onlyNumbers = false;

	while (onlyNumbers == false || numOfRounds < 1.0 || numOfRounds > 1000.0)
	{
		cout << "How many rounds would you like to play?" << endl;
		cout << "Please enter a value between 1 and 1000" << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireOnlyNumbers(menuInputTest);
		numOfRounds = atoi(menuInputTest.c_str());
		this->numOfRounds = numOfRounds;
		cout << endl;
	}

	// Prompt the user for the type of die for player 1

	onlyNumbers = false;

	while (onlyNumbers == false || playerOneDieType != 1.0 && playerOneDieType != 2.0)
	{
		cout << "Press 1 for Player One to use a regular die" << endl;
		cout << "Press 2 for Player One to use a loaded die";
		cout << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireOnlyNumbers(menuInputTest);
		playerOneDieType = atoi(menuInputTest.c_str());	
		this->playerOneDieType = playerOneDieType;
		cout << endl;
	}

	// Prompt the user for the type of die for player 2

	onlyNumbers = false;

	while (onlyNumbers == false || playerTwoDieType != 1.0 && playerTwoDieType != 2.0)
	{
		cout << "Press 1 for Player Two to use a regular die" << endl;
		cout << "Press 2 for Player Two to use a loaded die";
		cout << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireOnlyNumbers(menuInputTest);
		playerTwoDieType = atoi(menuInputTest.c_str());
		this->playerTwoDieType = playerTwoDieType;
		cout << endl;
	}

	// Prompt the user for player 1 number of die sides

	onlyNumbers = false;

	while (onlyNumbers == false || playerOneDieSides < 4.0 || playerOneDieSides > 20.0)
	{
		cout << "How many sides should Player One's die have?" << endl;
		cout << "Please enter a value between 4 and 20" << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireOnlyNumbers(menuInputTest);
		playerOneDieSides = atoi(menuInputTest.c_str());
		this->playerOneDieSides = playerOneDieSides;
		cout << endl;
	}

	// Prompt the user for player 2 number of die sides
    
	onlyNumbers = false;

	while (onlyNumbers == false || playerTwoDieSides < 4.0 || playerTwoDieSides > 20.0)
	{
		cout << "How many sides should Player Two's die have?" << endl;
		cout << "Please enter a value between 4 and 20" << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireOnlyNumbers(menuInputTest);
		playerTwoDieSides = atoi(menuInputTest.c_str());
		this->playerTwoDieSides = playerTwoDieSides;
		cout << endl;
	}
}


/***********************************************************************
** Description:   Method of game that takes the user selected values 
**                and creates the correct die or loaded die objects and 
**                calculates the game's result and then prints each
**                round and the final total and winner to the screen
***********************************************************************/

void Game::calculateAndPrint()
{
	// In game player variables

	int playerOneRoll = 0;
	int playerTwoRoll = 0;
	int playerOneScore = 0;
	int playerTwoScore = 0;

	// Create 2 arrays to hold the roll counts

	int playerOneRolls[numOfRounds];
	int playerTwoRolls[numOfRounds];

	// Seed the random function

	srand(time(NULL));

	// Create die objects for player 1

	if (playerOneDieType == 1)
	{
		Die diePlayerOne(playerOneDieSides);

		for (int i = 0; i < numOfRounds; i++)
		{
			playerOneRolls[i] = diePlayerOne.roll();
		}
	}

	if (playerOneDieType == 2) 
	{
		LoadedDie diePlayerOne(playerOneDieSides);

		for (int i = 0; i < numOfRounds; i++)
		{
			playerOneRolls[i] = diePlayerOne.roll();
		}
	}

	// Create die objects for player 2

	if (playerTwoDieType == 1)
	{
		Die diePlayerTwo(playerTwoDieSides);

		for (int i = 0; i < numOfRounds; i++)
		{
			playerTwoRolls[i] = diePlayerTwo.roll();
		}
	}

	if (playerTwoDieType == 2) 
	{
		LoadedDie diePlayerTwo(playerTwoDieSides);

		for (int i = 0; i < numOfRounds; i++)
		{
			playerTwoRolls[i] = diePlayerTwo.roll();
		}
	}

	cout << "Dice Rolling War Game Playing...";
	cout << endl << endl;

	// Loop through the number of rounds in the game

	for (int i = 0; i < numOfRounds; i++)
	{
		playerOneRoll = playerOneRolls[i];
		playerTwoRoll = playerTwoRolls[i];

		// Check for the winner of the round and increment score

		if (playerOneRoll > playerTwoRoll)
		{
			playerOneScore++;
		}
		if (playerTwoRoll > playerOneRoll)
		{
			playerTwoScore++;
		}

		// Print the results of the round

		cout << "Player 1: " << playerOneDieSides<< " sided ";

		if (playerOneDieType == 1)
		{
			cout << "regular die ";
		}
		else
		{
			cout << "loaded die ";
		}

		cout << "rolled: " << playerOneRoll << endl;

		cout << "Player 2: " << playerTwoDieSides << " sided ";

		if (playerTwoDieType == 1)
		{
			cout << "regular die ";
		}
		else
		{
			cout << "loaded die ";
		}

		cout << "rolled: " << playerTwoRoll;
		cout << endl << endl;
		cout << "The score is -" << endl;
		cout <<	"Player 1: " << playerOneScore << endl;
		cout << "Player 2: " << playerTwoScore;
		cout << endl << endl;
	}

	// Print the final score and the game's winner

	cout << endl << endl;
	cout << "**** Final score is ****" << endl;
	cout << "Player 1: " << playerOneScore << endl;
	cout << "Player 2: " << playerTwoScore;
	cout << endl << endl;
	cout << endl << endl;

	if (playerOneScore > playerTwoScore)
	{
		cout << "** Player ONE is the Winner! **";
	}
	else if (playerOneScore < playerTwoScore)
	{
		cout << "** Player TWO is the Winner! **";
	}
	else
	{
		cout << "The game is a draw...";
	}
	cout << endl << endl;
}


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

bool Game::requireOnlyNumbers(string menuInputTest)
{
	return menuInputTest.find_first_not_of("0123456789") == string::npos;
}


/*********************************************************************
** Description:   Second menu for after the game finishes. User selects
**                the menu choice of 1 or 2 to choose whether to quit
**                or play again. It returns 1 to restart
*********************************************************************/

int Game::endMenu()
{
	double endMenuChoice = 0.0;

	cout << endl << "Would you like to play again?";
	cout << endl << endl;
	cout << "Press 1 to Restart" << endl;
	cout << "Press 2 to Exit";
	cout << endl << endl;

	// Take in user input of either integer 1 or 2

	cin >> endMenuChoice;
	cout << endl;

	while (endMenuChoice != 1.0 && endMenuChoice != 2.0)
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Please enter either 1 or 2 " << endl << endl;
		cin >> endMenuChoice;
		cout << endl;
	}

	// Request to quit by choosing 2 on the menu

	if (endMenuChoice == 2.0)
	{
		cout << "Dice rolling War Game quitting - Goodbye!";
		cout << endl << endl;
		return 0;
	}

	// Request to restart by choosing 1 on the menu

	if (endMenuChoice == 1.0)
	{
		return 1;
	}
}