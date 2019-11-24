/*********************************************************************
** Program name:    Matrix Calculator
** Author:          Adam Wright
** Date:            4-7-2019
** Description:     Function that accesses an array and returns the
**                  determinant that it calculates. It's arguments 
**                  are the array and also the size of the array.
*********************************************************************/

#include "determinant.hpp"

int determinant(int *arr[], int size)
{
	int determinantValue = 0;

	// Figure out the determinant for a matrix of size 2
	if (size == 2) 
	{
		determinantValue = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
	}

	// Figure out the determinant for a matirx of size 3
	if (size == 3)
	{
		// Placeholders to hold the intermediate matrix values
		int a = 0;   
		int b = 0;
		int c = 0;

		a = arr[0][0] * ((arr[1][1] * arr[2][2]) - (arr[1][2] * arr[2][1]));
		b = arr[0][1] * ((arr[1][0] * arr[2][2]) - (arr[1][2] * arr[2][0]));
		c = arr[0][2] * ((arr[1][0] * arr[2][1]) - (arr[1][1] * arr[2][0]));

	    determinantValue = a - b + c;
	}

	return determinantValue;
}