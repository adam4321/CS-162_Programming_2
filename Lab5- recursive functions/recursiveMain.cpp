/***********************************************************************
** Program name:   Three Recursive Functions
** Author:         Adam Wright
** Date:           4/30/2019
** Description:    Program that gives the user a menu of three recursive
**                 functions that they can call. The program can be run 
**                 by typing recursive on the command line and then 
**                 following the prompts.
***********************************************************************/

#include <iostream>
#include <string>
#include "recursiveFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{
    int menuChoice = 0;
	string menuInputTest;
    bool restart = true;

    // Program wrapped in a do while to allow restarting
    do
    {
        cout << endl << endl;
        cout << "Please choose one of the following three functions";
        cout << endl << endl;

    	// While loop to validate user input of only 1 2 3 or 4  
        bool onlyNumbers = false;

		while (onlyNumbers == false || 
        menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4)
		{
			cout << "Press 1 to Reverse a string" << endl;
            cout << "Press 2 to Sum a set of numbers" << endl;
			cout << "Press 3 to Find the Triangular number" << endl;
			cout << "Press 4 to Exit";
			cout << endl << endl;
			cin >> menuInputTest;
			onlyNumbers = requireNumbers(menuInputTest);
			menuChoice = atoi(menuInputTest.c_str());
            cout << endl;
        }

        // Select 4 to exit
        if (menuChoice == 4)
        {
            return 0;
        }

        // Select 1 to run the string reverse function
        if (menuChoice == 1)
        {
            string input;

            cout << "Please enter a string to reverse.";
			cout << endl << endl;

            cin.clear();
            cin.ignore(256,'\n');
            getline(cin, input);
            
            cout << endl;
            cout << "This is the string reversed. ";
            cout << endl;

            reverseString(input);
        }

        // Select 2 to run the number summing function
        if (menuChoice == 2)
        {
            int size = 0;
            int input = 0;
            int counter = 0;
            int sum = 0;

            onlyNumbers = false;

		    while (onlyNumbers == false || size < 1 || size > 50)
		    {
                cout << "Please enter a number between 1 and 50." << endl;
			    cout << "You will then enter that amount of numbers to be ";
                cout <<  "summed.";
			    cout << endl << endl;
			    cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    size = atoi(menuInputTest.c_str());
                cout << endl;
            }

            // Create the number array and verify int input
            int *numbers = new int[size];

            onlyNumbers = false;

		    while (onlyNumbers == false || counter < size)
		    {
                cout << "Please enter " << size - counter;
                if (size - 1 == counter)
                {
                cout << " number." << endl;
                }
                else
                {
                cout << " numbers." << endl;
                }
			    cout << "This function will display the sum of the entered ";
                cout << "numbers.";
			    cout << endl << endl;
			    cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    input = atoi(menuInputTest.c_str());
                cout << endl;
                
                // If the input includes only 0-9 then add it into the array
                if (onlyNumbers == true)
                {
                    if (counter < size)
                    {
                        numbers[counter] = input;
                    }

                    counter++;
                }
            }

            sum = sumArray(numbers, size);

            cout << "The sum is " << sum;

            // Free the array memory
            delete []numbers;
        }

        // Select 3 to run the triangulate numbers function
        if (menuChoice == 3)
        {
            int input = 0;
            int triangulate = 0;

            onlyNumbers = false;

		    while (onlyNumbers == false || input < 1 || input > 10000)
		    {
                cout << "Please enter a number between 1 and 10,000." << endl;
			    cout << "This function will display it's triangular number.";
			    cout << endl << endl;
			    cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    input = atoi(menuInputTest.c_str());
                cout << endl;
            }

            triangulate = triangularNumber(input);

            cout << "The triangular number of " << input << " is ";
            cout << triangulate;
        }

      // Restart until the user chooses to exit
    } while (restart == true);
}