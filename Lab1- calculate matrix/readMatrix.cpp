/*********************************************************************
** Program name:    Matrix Calculator
** Author:          Adam Wright
** Date:            4-7-2019
** Description:     Function that allows the user to input values into
**                  the array that is passed in. The arguments are the
**                  empty dynamic array and the size of the array.
*********************************************************************/

#include <iostream>
#include <string>
#include "readMatrix.hpp"

using std::cin;
using std::cout;
using std::endl;

void readMatrix(int *arr[], int size)
{
	// Prompt the user for the corresponding amount of numbers based on
	// the size that is passed in which is either 2 or 3
	if (size == 2)
	{
		cout << endl << "Please enter 4 numbers" << endl << endl;
    }

	if (size == 3)
	{
		cout << endl << "Please enter 9 numbers" << endl << endl;
	}

	// Loop to fill the array with the correct amount of numbers
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];

			// Input validation to only allow numbers in the matrix
			while (!cin)
			{
				cin.clear();
				cin.ignore();
				cout << "Please enter a number" << endl << endl;
				cin >> arr[i][j];
			}
		}
	}
}