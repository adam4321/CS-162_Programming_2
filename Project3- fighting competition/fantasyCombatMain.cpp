/***********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
** Description:    Console game that pits pairs of characters against 
**                 each other where they each attack and defend during
**                 each round. You can run the game by typing 
**                 fantasyCombat into the command line and then following
**                 the prompts.
***********************************************************************/

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"

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
    int menuChoice = 0;
	string menuInputTest;
    bool restart = true;
    bool onlyNumbers = false;
    Character *characterOne;
    Character *characterTwo;

    // Seed the random function
    srand(time(NULL));

    do
    {
        cout << endl << endl;
        cout << "Welcome to the Fantasy Combat Game";
        cout << endl << endl;
        cout << "      *******************";
        cout << endl << endl;
        cout << "            *****";

    	// While loop to validate user input of only 1 2 
        onlyNumbers = false;

		while (onlyNumbers == false || startMenuChoice != 1 
                                    && startMenuChoice != 2)
		{
            cout << endl << endl;
			cout << "Press 1 to Play the Game" << endl;
			cout << "Press 2 to Exit";
			cout << endl << endl;
			cin >> menuInputTest;
			onlyNumbers = requireNumbers(menuInputTest);
			startMenuChoice = atoi(menuInputTest.c_str());
            cout << endl;
        }

        // Select 4 to exit
        if (startMenuChoice == 2)
        {
            cout << "Fantasy Combat Game Quitting  --  Goodbye!";
            cout << endl << endl;
            return 0;
        }

        // Start the game
        if (startMenuChoice == 1)
        {
            cout << "You will choose 2 characters from the" << endl;
            cout << "following list and they will do battle.";
            cout << endl << endl;

            // Select Character 1
            onlyNumbers = false;

		    while (onlyNumbers == false || menuChoice != 1 && menuChoice != 2
                     && menuChoice != 3 && menuChoice != 4 && menuChoice != 5)
		    {
			    cout << "Press 1 for character 1 to be a Vampire" << endl;
                cout << "Press 2 for character 1 to be a Barbarian" << endl;
			    cout << "Press 3 for character 1 to be a Blue Man" << endl;
			    cout << "Press 4 for character 1 to be Medusa" << endl;
                cout << "Press 5 for character 1 to be Harry Potter";
			    cout << endl << endl;
			    cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    menuChoice = atoi(menuInputTest.c_str());
                cout << endl;
            }

            if (menuChoice == 1)
            {
                characterOne = new Vampire();
            }
            
            if (menuChoice == 2)
            {
                characterOne = new Barbarian();
            }

            if (menuChoice == 3)
            {
                characterOne = new Blue_Men();
            }

            if (menuChoice == 4)
            {
                characterOne = new Medusa();
            }

            if (menuChoice == 5)
            {
                characterOne = new Harry_Potter();
            }

            // Select Character 2
            onlyNumbers = false;

		    while (onlyNumbers == false || menuChoice != 1 && menuChoice != 2
                     && menuChoice != 3 && menuChoice != 4 && menuChoice != 5)
		    {
			    cout << "Press 1 for character 2 to be a Vampire" << endl;
                cout << "Press 2 for character 2 to be a Barbarian" << endl;
			    cout << "Press 3 for character 2 to be a Blue Man" << endl;
			    cout << "Press 4 for character 2 to be Medusa" << endl;
                cout << "Press 5 for character 2 to be Harry Potter";
			    cout << endl << endl;
			    cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    menuChoice = atoi(menuInputTest.c_str());
                cout << endl;
            }

            if (menuChoice == 1)
            {
                characterTwo = new Vampire();
            }
            
            if (menuChoice == 2)
            {
                characterTwo = new Barbarian();
            }

            if (menuChoice == 3)
            {
                characterTwo = new Blue_Men();
            }

            if (menuChoice == 4)
            {
                characterTwo = new Medusa();
            }

            if (menuChoice == 5)
            {
                characterTwo = new Harry_Potter();
            }

            // Run the combat and print the rounds
            int roundCount = 1;

            while (characterOne->getStrength() > 0 &&
                   characterTwo->getStrength() > 0)
            {

                cout << "Round " << roundCount << endl << endl;

                cout << "Player one's attack - " << endl;
                characterTwo->defense(characterOne->attack(),
                                      characterOne->getMedusa());
                cout << endl << endl;

                if (characterTwo->getStrength() <= 0)
                {
                    cout << "********************************" << endl;
                    cout << "Player One is the Winner!" << endl;
                    cout << "********************************";
                    cout << endl << endl; 
                }

                else
                {
                    cout << "Player two's attack - " << endl;
                    characterOne->defense(characterTwo->attack(),
                                          characterTwo->getMedusa());
                    cout << endl << endl;

                    if (characterOne->getStrength() <= 0)
                    {
                        cout << "********************************" << endl;
                        cout << "Player Two is the Winner!" << endl;
                        cout << "********************************";
                        cout << endl << endl;
                    }
                }

                roundCount++;
            }

            // Free the heap memory
            delete characterOne;
            delete characterTwo;
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
