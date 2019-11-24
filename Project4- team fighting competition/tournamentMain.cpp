/***********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
** Description:    Console game that pits teams of characters against 
**                 each other where they each attack and defend during
**                 each round. You can run the game by typing 
**                 tournament into the command line and then following
**                 the prompts.
***********************************************************************/

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"
#include "Queue.hpp"

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
    bool onlyNumbers = false;
    Character *characterOne = NULL;
    Character *characterTwo = NULL;
    Queue teamOne;
    Queue teamTwo;
    Queue loserStack;

    // Seed the random function
    srand(time(NULL));

    do
    {
        // Variables to find how many characters to prompt for
        int numOnTeam = 0;
        int fighterCount = 1;

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


        // Select 2 to exit
        if (startMenuChoice == 2)
        {
            cout << "Fantasy Combat Game Quitting  --  Goodbye!";
            cout << endl << endl;
            return 0;
        }


        // Start the game by choosing the number of players on a team
        if (startMenuChoice == 1)
        {
            // Choose the team size
            onlyNumbers = false;

		    while (onlyNumbers == false || numOnTeam < 1 || numOnTeam > 10)
		    {
			    cout << "This is a 2 player game.";
                cout << endl << endl;
                cout << "Choose a number of fighters for each team" << endl;
			    cout << "between 1 and 10";
			    cout << endl << endl;
			    cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    numOnTeam = atoi(menuInputTest.c_str());
                cout << endl << endl;
            }


            // Select Team 1 characters until numOnTeam is reached
            while (fighterCount <= numOnTeam)
            {
                string characterName;
                onlyNumbers = false;

                while (onlyNumbers == false || menuChoice != 1 && menuChoice != 2
                        && menuChoice != 3 && menuChoice != 4 && menuChoice != 5)
                {
                    cout << "Team ONE";
                    cout << endl << endl;
                    cout << "Press 1 for character " << fighterCount
                     << " to be a Vampire" << endl;
                    cout << "Press 2 for character " << fighterCount
                     <<" to be a Barbarian" << endl;
                    cout << "Press 3 for character "  << fighterCount 
                     << " to be a Blue Man" << endl;
                    cout << "Press 4 for character "  << fighterCount
                     << " to be Medusa" << endl;
                    cout << "Press 5 for character "  << fighterCount
                     << " to be Harry Potter";
                    cout << endl << endl;
                    cin >> menuInputTest;
                    onlyNumbers = requireNumbers(menuInputTest);
                    menuChoice = atoi(menuInputTest.c_str());
                    cout << endl;
                }


                // Ask for the fighter one's name
                cout << "Please enter a Name for your fighter";
                cout << endl << endl;
                cin >> characterName;
                cout << endl << endl;

                // Create fighter ONE
                if (menuChoice == 1)
                {
                    characterOne = new Vampire();
                    characterOne->setName(characterName);                  
                    teamOne.addBack(characterOne);
                }
                
                if (menuChoice == 2)
                {
                    characterOne = new Barbarian();
                    characterOne->setName(characterName);
                    teamOne.addBack(characterOne);
                }

                if (menuChoice == 3)
                {
                    characterOne = new Blue_Men();
                    characterOne->setName(characterName);
                    teamOne.addBack(characterOne);
                }

                if (menuChoice == 4)
                {
                    characterOne = new Medusa();
                    characterOne->setName(characterName);                   
                    teamOne.addBack(characterOne);
                }

                if (menuChoice == 5)
                {
                    characterOne = new Harry_Potter();
                    characterOne->setName(characterName);                   
                    teamOne.addBack(characterOne);
                }

                characterOne = NULL;
                fighterCount++;
            }


            // Select Team 2 until numOnTeam is reached
            fighterCount = 1;

            while (fighterCount <= numOnTeam)
            {
                string characterName;
                onlyNumbers = false;

                while (onlyNumbers == false || menuChoice != 1 && menuChoice != 2
                        && menuChoice != 3 && menuChoice != 4 && menuChoice != 5)
                {
                    cout << "Team TWO";
                    cout << endl << endl;
                    cout << "Press 1 for character " << fighterCount
                     << " to be a Vampire" << endl;
                    cout << "Press 2 for character " << fighterCount
                     <<" to be a Barbarian" << endl;
                    cout << "Press 3 for character "  << fighterCount 
                     << " to be a Blue Man" << endl;
                    cout << "Press 4 for character "  << fighterCount
                     << " to be Medusa" << endl;
                    cout << "Press 5 for character "  << fighterCount
                     << " to be Harry Potter";
                    cout << endl << endl;
                    cin >> menuInputTest;
                    onlyNumbers = requireNumbers(menuInputTest);
                    menuChoice = atoi(menuInputTest.c_str());
                    cout << endl;
                }


                // Ask for the fighter two's name
                cout << "Please enter a Name for your fighter";
                cout << endl << endl;
                cin >> characterName;
                cout << endl << endl;

                // Create fighter TWO
                if (menuChoice == 1)
                {
                    characterTwo = new Vampire();  
                    characterTwo->setName(characterName);                  
                    teamTwo.addBack(characterTwo);
                }
                
                if (menuChoice == 2)
                {
                    characterTwo = new Barbarian(); 
                    characterTwo->setName(characterName);                                     
                    teamTwo.addBack(characterTwo);
                }

                if (menuChoice == 3)
                {
                    characterTwo = new Blue_Men();  
                    characterTwo->setName(characterName);                                    
                    teamTwo.addBack(characterTwo);
                }

                if (menuChoice == 4)
                {
                    characterTwo = new Medusa();
                    characterTwo->setName(characterName);                                     
                    teamTwo.addBack(characterTwo);
                }

                if (menuChoice == 5)
                {
                    characterTwo = new Harry_Potter();
                    characterTwo->setName(characterName);                                      
                    teamTwo.addBack(characterTwo);
                }

                characterTwo = NULL;
                fighterCount++;
            }


            // Run the combat and print the rounds
            int teamOneScore = 0;
            int teamTwoScore = 0;
            int roundCount = 1;

            do
            {
                cout << "********************" << endl;
                cout << "Battle Round " << roundCount << endl;
                cout << "********************";
                cout << endl << endl;


                // Test the Queues' states at each round's start

                // teamOne.printQueue();
                // cout << endl;
                // teamTwo.printQueue();
                // cout << endl;
                // loserStack.printQueue();
                // cout << endl << endl;


                characterOne = teamOne.getFront();
                characterTwo = teamTwo.getFront();

                cout << "Team 1: " << characterOne->getType() << " named ";
                cout << characterOne->getName() << endl;
                cout << "VS" << endl;
                cout << "Team 2: " << characterTwo->getType() << " named ";
                cout << characterTwo->getName();
                cout << endl << endl;


                while (characterOne->getStrength() > 0 &&
                    characterTwo->getStrength() > 0)
                {
                    // Player One's attack
                    characterTwo->defense(characterOne->attack(),
                                        characterOne->getMedusa());

                    if (characterTwo->getStrength() <= 0)
                    {
                        cout << "********************************" << endl;
                        cout << "Team 1 won the round" << endl;
                        cout << "********************************";
                        cout << endl << endl;

                        teamOneScore += 2;
                        teamTwoScore--;

                        cout << characterTwo->getName() << " killed by ";
                        cout << characterOne->getName() << endl;

                        loserStack.addBack(characterTwo);
                        teamTwo.removeFront();

                        // Winner recovers health
                        int strength = characterOne->getStrength();
                        double recovery = 1 + ((rand() % 10 + 1) / 100);
                        strength = strength * recovery;

                        cout << characterOne->getName() << " recovers ";
                        cout << strength << " strength" << endl;

                        characterOne->setStrength(strength);
                        teamOne.addBack(characterOne);
                        teamOne.removeFront();
                    }


                    else
                    {
                        // Player Two's attack
                        characterOne->defense(characterTwo->attack(),
                                            characterTwo->getMedusa());

                        if (characterOne->getStrength() <= 0)
                        {
                            cout << "********************************" << endl;
                            cout << "Team 2 won the round" << endl;
                            cout << "********************************";
                            cout << endl << endl;

                            teamTwoScore += 2;
                            teamOneScore--;

                            cout << characterOne->getName() << " killed by ";
                            cout << characterTwo->getName() << endl;

                            loserStack.addBack(characterOne);
                            teamOne.removeFront();

                            // Winner recovers health
                            int strength = characterTwo->getStrength();
                            double recovery = 1 + ((rand() % 10 + 1) / 100);
                            strength = strength * recovery; 

                            cout << characterTwo->getName() << " recovers ";
                            cout << strength << " strength" << endl;

                            characterTwo->setStrength(strength);
                            teamTwo.addBack(characterTwo);
                            teamTwo.removeFront();
                        }
                    }
                }

                cout << endl;
                roundCount++;

            }while (teamOne.isEmpty() == false && teamTwo.isEmpty() == false);


            // Display the winning team and score
            cout << endl;
            cout << "***************************";
            cout << endl << endl;
            cout << "Team One's final score is " << teamOneScore << endl;
            cout << "Team Two's final score is " << teamTwoScore;
            cout << endl << endl;
            cout << "***************************";
            cout << endl << endl;

            if (teamOneScore == teamTwoScore)
            {
                cout << "The game is a tie";
            }

            else if (teamOneScore > teamTwoScore)
            {
                cout << "Team One is the Winner!";
            }

            else
            {
                cout << "Team Two is the Winner!";
            }
            
            cout << endl << endl;
            cout << "***************************" << endl;
            cout << endl << endl;


            // Ask if the user wants to see the loser list
            onlyNumbers = false;

		    while (onlyNumbers == false || menuChoice != 1 && menuChoice != 2)
		    {
                cout << "Would you like to see the list of losers?";
                cout << endl << endl;
			    cout << "Press 1 to view the list" <<  endl;
                cout << "Press 2 to skip it";
			    cout << endl << endl;
			    cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    menuChoice = atoi(menuInputTest.c_str());
                cout << endl << endl;
            }

            if (menuChoice == 1)
            {
                cout << "***************" << endl;
                cout << "Loser List: " << endl;
                cout << "***************";
                cout << endl << endl;
                loserStack.printQueue();
                cout << endl;
            }
            

            // Free the heap memory
            while (teamOne.isEmpty() == false)
            {
                teamOne.deleteFront();
            }

            while (teamTwo.isEmpty() == false)
            {
                teamTwo.deleteFront();
            }
            
            while (loserStack.isEmpty() == false)
            {
                loserStack.deleteFront();
            }

            delete characterOne;
            delete characterTwo;
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
