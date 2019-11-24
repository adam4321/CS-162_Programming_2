/*********************************************************************
** Program name:    Matrix Calculator
** Author:          Adam Wright
** Date:            4-7-2019
** Description:     Program that dynamically allocates a 2x2 or 3x3
**                  array and then returns the determinant of that
**                  matrix. Run the program by typing matrixCalculator
**                  into the console and then following the prompts.
*********************************************************************/

#include <iostream>
#include <string>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	int size = 0;

	// Prompt the user for either 2 or 3 to choose the array size
	cout << endl << "Please enter either the number 2 or 3" << endl << endl;
    cout << "2 will select a 2x2 matrix" << endl;
    cout << "3 will select a 3x3 matrix" << endl << endl;
	cin >> size;

	// While loop to only allow the user to enter 2 or 3
	while (size != 2 && size != 3)
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter either 2 or 3 " << endl << endl;
		cin >> size;
	}

	// Create the 2d array of the correct size
	int **inputMatrix = new int*[size];

	for (int i = 0; i < size; i++)
	{
		inputMatrix[i] = new int[size];
	}

	// Call the readMatrix function with the array and it's size
	readMatrix(inputMatrix, size);

	// Print the entered matrix to the screen
	cout << endl << "This is a display of the matrix: " << endl << endl;

	for (int i = 0; i < size; i++) 
	{
		if (i != 0)
		{
			cout << endl;
		}
		for (int j = 0; j < size; j++)
		{
			cout << inputMatrix[i][j] << " ";
		}
	}
	cout << endl << endl;

	// Call the determinant function to return and print the value
	cout << "The determinant for the matrix is: " << determinant(inputMatrix, size);
	cout << endl << endl;

	// Free the array memory
	for (int i = 0; i < size; i++)
	{
		delete[] inputMatrix[i];
	}
    
	delete[] inputMatrix;

    return 0;
}