/***********************************************************************
** Program name:   Compare recursion and iteration
** Author:         Adam Wright
** Date:           6/2/2019
** Description:    Program that compares a recursive and an iterative
**                 implementation of a Fibonacci algorith to find the 
**                 difference in their run times. The program can be run
**                 by typing compare into the console and then following
**                 the prompts.
***********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

#include "iterativeFib.hpp"
#include "recursiveFib.hpp"

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
    unsigned long long int inputNumber = 1;

    do
    {
    	// Do While loop to allow restarting 
        onlyNumbers = false;

        cout << endl << endl;
        cout << "***************************************" << endl;
        cout << "Recursion vs Iteration test" << endl;
        cout << "***************************************";
        cout << endl << endl;

        // Print the menu each time through the loop
        onlyNumbers = false;

		while (onlyNumbers == false || menuChoice != 1 && menuChoice != 2)
		{
			cout << "Press 1 to test the Fibonacci runtime of a number" << endl;
            cout << "Press 2 to Exit";
 			cout << endl << endl;
			cin >> menuInputTest;
			onlyNumbers = requireNumbers(menuInputTest);
			menuChoice = atoi(menuInputTest.c_str());
            cout << endl;
        }

        // Select 2 to exit
        if (menuChoice == 2)
        {
            cout << "Recursion vs Iteration test Quitting  --  Goodbye!";
            cout << endl << endl;

            return 0;
        } 

        // Select 1 to run buffer function
        if (menuChoice == 1)
        {
            clock_t t1;
            clock_t t2;

            onlyNumbers = false;

            while (onlyNumbers == false || inputNumber < 1 || inputNumber > 100)
            {
                cout << "Please enter a number between 1 and 100" << endl;
                cout << "to pass into the 2 algorithms and return the" <<endl;
                cout << "Nth Fibonacci number";
                cout << endl << endl;
                cin >> menuInputTest;
			    onlyNumbers = requireNumbers(menuInputTest);
			    inputNumber = atoi(menuInputTest.c_str());
                cout << endl;
            }


            cout << "Finding " << inputNumber << "th fibonacci number....";
            cout << endl << endl;
            cout << "Calling Iterative Fibonacci implementation" << endl;

            t2 = clock();
            IterativeFib itfib(inputNumber);
            itfib.PrintFibonacci();
            t2 = clock() - t2;
            cout << "The Iterative runtime is " << t2;
            cout << " clicks (" << ((float)t2)/CLOCKS_PER_SEC << " seconds)" << endl;


            cout << endl;
            cout << "Calling Recursive Fibonacci implementation" << endl;

            t1 = clock();
            RecursiveFib refib(inputNumber);
            refib.PrintFibonacci();
            t1 = clock() - t1;
            cout << "The Recursive runtime is " << t1;
            cout << " clicks (" << ((float)t1)/CLOCKS_PER_SEC << " seconds)" << endl;


            cout << endl << "Done!!!!";
            cout << endl;
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