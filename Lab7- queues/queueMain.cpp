/***********************************************************************
** Program name:   Queue Lab
** Author:         Adam Wright
** Date:           5/15/2019
** Description:    Lab that explores using functions for an implementation
**                 of a queue with a linked list. The program can be run by 
**                 typing queue into the console and then following
**                 the prompts.
***********************************************************************/

#include "Queue.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool requireNumbers(string menuInputTest);


int main()
{
    int menuChoice = 0;
    string menuInputTest;
    bool onlyNumbers = false;
    int inputNumber;
    Queue queue;

    do
    {
    	// Do While loop to allow restarting 
        onlyNumbers = false;

        cout << endl << endl;
        cout << "***************************************" << endl;
        cout << "An Exploration of Queues" << endl;
        cout << "***************************************";
        cout << endl << endl;
        cout << "Please choose one of the options" << endl;
        cout << "from the following list.";
        cout << endl << endl;

        // Print the menu each time through the loop
        onlyNumbers = false;

		while (onlyNumbers == false || 
                   menuChoice != 1 && menuChoice != 2 && menuChoice != 3 
                && menuChoice != 4 && menuChoice != 5)
		{
			cout << "Press 1 to Add a value to the back of the Queue" << endl;
            cout << "Press 2 to Display the front value of the Queue" << endl;
			cout << "Press 3 to Remove the front node of the Queue" << endl;
			cout << "Press 4 to Print the Queue" << endl;
            cout << "Press 5 to exit";
 			cout << endl << endl;
			cin >> menuInputTest;
			onlyNumbers = requireNumbers(menuInputTest);
			menuChoice = atoi(menuInputTest.c_str());
            cout << endl;
        }

        // Select 1 to add a node to the front of the queue
        if (menuChoice == 1)
        {
            onlyNumbers = false;

            while (onlyNumbers == false || inputNumber < 0
                                        || inputNumber > 1000)
            {
                cout << "Please enter a number between 0 and 1,000";
                cout << endl << endl;
                cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    inputNumber = atoi(menuInputTest.c_str());
                cout << endl;
            }

            cout << "Adding a node to the back of the Queue..." << endl;
            queue.addBack(inputNumber);
        }

        // Select 2 to print the first node
        if (menuChoice == 2)
        {
            cout << "The first value in the Queue is: ";

            // Check in main to avoid printing isEmpty return value
            if (queue.isEmpty() == true)
            {
                cout << endl << endl;
                cout << "The list is empty";
                cout << endl << endl;
            }
            else
            {
                cout << queue.getFront();
                cout << endl << endl;
            }
        }

        // Select 3 to delete the head node
        if (menuChoice == 3)
        {
            cout << "Deleting the first node...";
            queue.removeFront();
            cout << endl << endl;
        }

        // Select 4 to delete the tail node
        if (menuChoice == 4)
        {
            cout << "Printing the Queue...";
            cout << endl<< endl;
            queue.printQueue();
            cout << endl << endl;
        }  

        // Select 5 to exit
        if (menuChoice == 5)
        {
            cout << "Queue Lab Quitting  --  Goodbye!";
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