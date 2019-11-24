/*********************************************************************
** Program name:   Three Recursive Functions
** Author:         Adam Wright
** Date:           4/30/2019
** Description:    Recursive function definitions file 
*********************************************************************/

#include "recursiveFunctions.hpp"

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


/*********************************************************************
** Description:   Function to reverse a string recursively. It takes
**                the string as an argument and prints the reversed
**                string.
*********************************************************************/
void reverseString(string input)
{
    // Base case where string parameter is empty
    if (input.size() == 0) 
    { 
        cout << "\n"; 
    } 

    // Pull out the second character through the last and print the first
    else
    {
        reverseString(input.substr(1)); 
    }
    
    cout << input[0]; 
}

/*********************************************************************
** Description:   Function to sum an array of integers recursively. It
**                takes a pointer to the array and the size of the 
**                array as arguments.
*********************************************************************/
int sumArray(int *numbers, int size)
{
    // Base case where size parameter is 0
    if (size == 0)
    {
        return 0;
    }

    // Add the last 2 numbers and decrement size 
    else
    {
        return(sumArray(numbers, size - 1) + numbers[size - 1]);
    }
}

/*********************************************************************
** Description:   Function to find the triangular number of the number
**                that is passed in as it's argument.
*********************************************************************/
int triangularNumber(int input)
{
    // Base case where input parameter is 0
    if (input == 1)
    {
        return input;
    }

    // Summmation of n + n-1 down to 1
    else
    {
        return(triangularNumber(input - 1) + input);
    }
}