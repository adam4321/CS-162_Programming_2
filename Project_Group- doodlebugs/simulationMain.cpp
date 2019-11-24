/***********************************************************************
** Program name:   Predator Prey simulation
** Author:         Group 16
** Date:           5/3/2019
** Description:    Console game that pits Ants against Doodlebugs. It can
**                 be run by typing simulation into the command line and
**                 following the prompts.
***********************************************************************/

#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool requireNumbers(string menuInputTest);


int main()
{
    int startMenuChoice = 0;
    string menuInputTest;
    bool onlyNumbers = false;
    int steps = 0;
    int antTotal = 100;
    int doodlebugTotal = 5;

    // Seed the random function
    srand(time(NULL));

    do
    {
        int antCount = 0;
        int doodlebugCount = 0;

        cout << endl << endl;
        cout << "Welcome to the Predator Prey Simulation";
        cout << endl << endl;
        cout << "        *******************";
        cout << endl << endl;
        cout << "               *****";

    	// While loop to validate user input of only 1 2 
        onlyNumbers = false;  

		while (onlyNumbers == false || startMenuChoice != 1 
                                    && startMenuChoice != 2)
		{
            cout << endl << endl;
			cout << "Press 1 to Run the Simulation" << endl;
			cout << "Press 2 to Exit";
			cout << endl << endl;
			cin >> menuInputTest;
			onlyNumbers = requireNumbers(menuInputTest);
			startMenuChoice = atoi(menuInputTest.c_str());
            cout << endl;
        }

        // Select 2 to exit
        if (startMenuChoice == 2)
        {
            cout << "Predator Prey Simulation Quitting  --  Goodbye!";
            cout << endl << endl;
            return 0;
        }

        // Select 1 to start the simulation
        if (startMenuChoice == 1)
        {
            // Set the number of steps
            onlyNumbers = false;

		    while (onlyNumbers == false || steps < 1 || steps > 10000)
		    {
                cout << "Please enter an integer number between" << endl;
                cout << "1 and 10,000 for the amount of time steps" << endl;
                cout << "that you would like the simulation to run for.";
			    cout << endl << endl;
			    cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    steps = atoi(menuInputTest.c_str());
                cout << endl;
            }

            // Print the user enter number of steps
            cout << "Simulation running for " << steps << " steps...";
            cout << endl << endl;

            // Create the simulation board
	        Critter ***board = new Critter**[20];

	        for (int i = 0; i < 20; i++)
	        {
		        board[i] = new Critter*[20];
	        }

	        // Fill the initial board state with null pointers
	        for (int i = 0; i < 20; i++)
	        {
		        for (int j = 0; j < 20; j++)
		        {
			        board[i][j] = NULL;
		        }
            }

            // Populate the board with Ants
            while (antCount < antTotal)
            {
                // Random x and y from 0 - 19
                int x = rand() % 20;
                int y = rand() % 20;
                
                if (board[x][y] == NULL)
                {
                    board[x][y] = new Ant(x,y);
                    antCount++;
                }
            }

            // Populate the board with Doodlebugs
            while (doodlebugCount < doodlebugTotal)
            {
                // Random x and y from 0 - 19
                int x = rand() % 20;
                int y = rand() % 20;

                if (board[x][y] == NULL)
                {
                    board[x][y] = new Doodlebug(x,y);
                    doodlebugCount++;
                }
            }


            // RUN THE SIMULATION for the Number of Steps Chosen
            for(int k = 0; k < steps; k++)
            {
                cout << "Step " << k + 1;
                cout << endl << endl;

                // Move the Ants
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (board[i][j] != NULL 
                         && board[i][j]->getSymbol() == 'O')
                        {
                            board[i][j]->move(board);
                        }
                    }
                }

                // Breed the Ants
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (board[i][j] != NULL 
                         && board[i][j]->getSymbol() == 'O')
                        {
                            board[i][j]->breed(board);
                        }
                    }
                }

                // Move the Doodlebugs and eat Ants
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (board[i][j] != NULL 
                         && board[i][j]->getSymbol() == 'X')
                        {
                            board[i][j]->move(board);
                        }
                    }
                }

                // Breed the Doodlebugs
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (board[i][j] != NULL 
                         && board[i][j]->getSymbol() == 'X')
                        {
                            board[i][j]->breed(board);
                        }
                    }
                }

                // Starve the Doodlebugs
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (board[i][j] != NULL 
                         && board[i][j]->getSymbol() == 'X')
                        {
                            if (board[i][j]->getStarved() > 0
                            &&  board[i][j]->getStarved() % 3 == 0)
                            {
                                delete board[i][j];
                                board[i][j] = NULL;
                            }
                        }
                    }
                }

                // Print the board
                for (int i = 0; i < 20; i++)
		        {
			        if (i != 0)
			        {
				        cout << endl;
			        }
			        for (int j = 0; j < 20; j++)
			        {
                        if (board[i][j] == NULL)
                        {
                            cout << " " << '.';
                        }
                        else
                        {
					        cout << board[i][j]->getSymbol() << '.';
                        }
                    }
			    }
                cout << endl << endl;
            }

            // Free the array memory
	        for (int i = 0; i < 20; i++)
	        {
                for (int j = 0; j < 20; j++)
                {
                    delete board[i][j]; 
                }

                delete[] board[i];
	        }
            delete[] board;
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