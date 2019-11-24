/*********************************************************************
** Program name:   Langton's Ant
** Author:         Adam Wright
** Date:           4/8/2019
** Description:    Function that implements the Ant class. It takes in
**                 a menu class as it's single argument. The ant class
**                 contains all of the ant movement logic and it also
**                 prints the board.
*********************************************************************/

#include "Menu.hpp"
#include "Ant.hpp"

/*********************************************************************
** Description:   Constructor that initializes an ant object
*********************************************************************/
Ant::Ant(Menu menu)
{
	int sizeX = 0;
	int sizeY = 0;
	int numSteps = 0;
	int startRow = 0;
	int startCol = 0;
	int antX = 0;
	int antY = 0;
	int pointUp = 1;
	int pointRight = 2;
	int pointDown = 3;
	int pointLeft = 4;
	int direction = pointLeft;

	sizeX = menu.getSizeX();
	sizeY = menu.getSizeY();
	startRow = menu.getStartRow();
	startCol = menu.getStartCol();	
	numSteps = menu.getNumSteps();
	antX = startRow;
	antY = startCol;

	// Create the 2D board
	int boardSize = sizeX * sizeY;

	char **board = new char*[boardSize];

	for (int i = 0; i < boardSize; i++)
	{
		board[i] = new char[boardSize];
	}

	// Fill the initial board state with white spaces
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			board[i][j] = ' ';
		}
	}

	cout << "Simulation Running..." << endl;

	// Loop for the number of steps chosen
	for (int k = 0; k < numSteps; k++)
	{
		// Bahavior for white square holding a ' '
		if (board[antX][antY] == ' ')
		{
			// Turn right 90 degrees
			if (direction == pointUp)
			{
				direction = pointRight;
			}
			else if (direction == pointRight)
			{
				direction = pointDown;
			}
			else if (direction == pointDown)
			{
				direction = pointLeft;
			}
			else if (direction == pointLeft)
			{
				direction = pointUp;
			}

			// Change the space's color to black
			board[antX][antY] = '#';

			// Turn around if the ant is at the edge
			if (antX == 0 && direction == pointUp)
			{
				direction = pointDown;
			}
			else if (antX == sizeX -1 && direction == pointDown)
			{
				direction = pointUp;
			}
			else if (antY == 0 && direction == pointLeft)
			{
				direction = pointRight;
			}
			else if (antY == sizeY -1 && direction == pointRight)
			{
				direction = pointLeft;
			}

			// Move to the next space based on current direction
			if (direction == pointUp)
			{
				antX = antX - 1;
			}
			else if (direction == pointRight)
			{
				antY = antY + 1;
			}
			else if (direction == pointDown)
			{
				antX = antX + 1;
			}
			else if (direction == pointLeft)
			{
				antY = antY - 1;
			}
		}

		// Behavior for black square holding a '#'
		else if (board[antX][antY] == '#')
		{
			//Turn left 90 degrees
			if (direction == pointUp)
			{
				direction = pointLeft;
			}
			else if (direction == pointLeft)
			{
				direction = pointDown;
			}
			else if (direction == pointDown)
			{
				direction = pointRight;
			}
			else if (direction == pointRight)
			{
				direction = pointUp;
			}

			// Chage the space's color to white
			board[antX][antY] = ' ';

			// Turn around if the ant is at the edge
			if (antX == 0 && direction == pointUp)
			{
				direction = pointDown;
			}
			else if (antX == sizeX -1 && direction == pointDown)
			{
				direction = pointUp;
			}
			else if (antY == 0 && direction == pointLeft)
			{
				direction = pointRight;
			}
			else if (antY == sizeY -1 && direction == pointRight)
			{
				direction = pointLeft;
			}

			// Move to the next space based on current direction
			if (direction == pointUp)
			{
				antX = antX - 1;
			}
			else if (direction == pointRight)
			{
				antY = antY + 1;
			}
			else if (direction == pointDown)
			{
				antX = antX + 1;
			}
			else if (direction == pointLeft)
			{
				antY = antY - 1;
			}
		}

		// Print the board with periods to show the orientation
		for (int i = 0; i < sizeX; i++)
		{
			if (i != 0)
			{
				cout << endl;
			}
			for (int j = 0; j < sizeY; j++)
			{
				if (i == antX && j == antY)
				{
					cout << '*' << '.';
				}
				else
				{
					cout << board[i][j] << '.';
				}
			}
		}
		cout << endl << endl;
	}

	cout << "Display of the ant's moves on the board" << endl;

	// Free the array memory
	for (int i = 0; i < boardSize; i++)
	{
		delete[] board[i];
	}
    
	delete[] board;

	// Call the endMenu function to play again or quit
	menu.endMenu();
}
