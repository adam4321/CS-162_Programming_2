/***********************************************************************
** Program name:   Doubly Linked List
** Author:         Adam Wright
** Date:           5/7/2019
** Description:    Lab that explores using functions for an implementation
**                 of a doubly linked list. The program can be run by 
**                 typing linkedList into the console and then following
**                 the prompts.
***********************************************************************/

#include "Node.hpp"
#include "listFunctions.hpp"

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
    int listInputNumber;
    List list;

    do
    {
    	// Do While loop to allow restarting 
        onlyNumbers = false;

        cout << endl << endl << endl;
        cout << "DOING BOTH EXTRA CREDIT OPTIONS";
        cout << endl << endl;
        cout << "***************************************" << endl;
        cout << "An Exploration of Doubly Linked Lists" << endl;
        cout << "***************************************";
        cout << endl << endl;
        cout << "Please choose one of the options" << endl;
        cout << "from the following list.";
        cout << endl << endl;

        // Print the menu each time through the loop
        onlyNumbers = false;

		while (onlyNumbers == false || 
                   menuChoice != 1 && menuChoice != 2 && menuChoice != 3 
                && menuChoice != 4 && menuChoice != 5 && menuChoice != 6
                && menuChoice != 7 && menuChoice != 8 && menuChoice != 9)
		{
			cout << "Press 1 to Add a new node to the head" << endl;
            cout << "Press 2 to Add a new node to the tail" << endl;
			cout << "Press 3 to Delete the head node of the list" << endl;
			cout << "Press 4 to Delete the tail node of the list" << endl;
            cout << "Press 5 to Print the list in reverse" << endl;
            cout << "Press 6 to Print the Head node" << endl; 
            cout << "Press 7 to Print the Tail node" << endl;
            cout << "Press 8 to populate the list from file data" << endl;
            cout << "Press 9 to exit";
 			cout << endl << endl;
			cin >> menuInputTest;
			onlyNumbers = requireNumbers(menuInputTest);
			menuChoice = atoi(menuInputTest.c_str());
            cout << endl;
        }

        // Select 9 to exit
        if (menuChoice == 9)
        {
            cout << "Doubly Linked List Lab Quitting  --  Goodbye!";
            cout << endl << endl;

            return 0;
        }

        // Select 1 to add a node to the head
        if (menuChoice == 1)
        {
            onlyNumbers = false;

            while (onlyNumbers == false || listInputNumber < 0
                                        || listInputNumber > 1000)
            {
                cout << "Please enter a number between 0 and 1,000";
                cout << endl << endl;
                cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    listInputNumber = atoi(menuInputTest.c_str());
                cout << endl;
            }

            cout << "Adding a node to the head...";
            list.addToHead(listInputNumber);
            cout << endl << endl;
            list.print();
        }

        // Select 2 to add a node to the tail
        if (menuChoice == 2)
        {
            onlyNumbers = false;

            while (onlyNumbers == false || listInputNumber < 0
                                        || listInputNumber > 1000)
            {
                cout << "Please enter a number between 0 and 1,000";
                cout << endl << endl;
                cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    listInputNumber = atoi(menuInputTest.c_str());
                cout << endl;
            }

            cout << "Adding a node to the tail...";
            list.addToTail(listInputNumber);
            cout << endl << endl;
            list.print();
        }

        // Select 3 to delete the head node
        if (menuChoice == 3)
        {
            cout << "Deleting the head node...";
            list.deleteHead();
            cout << endl << endl;
            list.print();
        }

        // Select 4 to delete the tail node
        if (menuChoice == 4)
        {
            cout << "Deleting the tail node...";
            list.deleteTail();
            cout << endl<< endl;
            list.print();
        }

        // Select 5 to print the list backwards (assignment wants forward hidden)
        if (menuChoice == 5)
        {
            cout << "Printing the list in Reverse...";
            cout << endl << endl;
            list.printReverse();
        }

        // Print the head node
        if (menuChoice == 6)
        {
            cout << "Printing the head node...";
            cout << endl << endl;
            list.getHead();
        }

        // Print the tail node
        if (menuChoice == 7)
        {        
            cout << "Printing the tail node...";
            cout << endl << endl;
            list.getTail();
        }

        // Fill the list from an included text file
        if (menuChoice == 8)
        {
            cout << "Populating the list from file...";
            list.populate();
            cout << endl << endl;
            list.print();
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