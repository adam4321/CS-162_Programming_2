/************************************************************************
** Program name:   Search Sort Lab
** Author:         Adam Wright
** Date:           5/21/2019
** Description:    Program that implements 2 search and 1 sort algorithms
**                 It can be run by typing searchSort into the console
**                 and following the prompts.
************************************************************************/

#include "algorithms.hpp"

/*********************************************************************
** Description:   Simple string searching function that takes an 
**                unsorted array and the target integer as arguments  
**                and returns a string message of whether the target
**                was found or not.
*********************************************************************/
string simpleSearch(int inputArr[], int targetNum, int size)
{
    // If the value is in the array then return found
    for (int i = 0; i < size; i++)
    {
        if (inputArr[i] == targetNum)
        {
            return "target value found";
        }
    }

    // Otherwise the loop ends and return not found
    return "target value not found";  
}

/*********************************************************************
** Description:   Function that implements selection sort. It takes an
**                array and the size of the array as arguments. It is
**                implemented from the C++ early objects rev.9 textbook
**                by Gaddis et al and is found on page 619
*********************************************************************/
void selectionSort(int inputArr[], int size)
{
    int startScan, minIndex, minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = inputArr[startScan];

        for (int index = startScan + 1; index < size; index++)
        {
            if (inputArr[index] < minValue)
            {
                minValue = inputArr[index];
                minIndex = index;
            }
        }

        inputArr[minIndex] = inputArr[startScan];
        inputArr[startScan] = minValue;
    }

    // Print the sorted array
    for (int i = 0; i < size; i++)
    {
        cout << inputArr[i];
    }
}

/*********************************************************************
** Description:   Function that implements binary search. It takes an
**                array, the target value, and the array size as 
**                arguments and returns a string of whether the target
**                was found. It is implemented from the C++ early 
**                objects rev.9 textbook by Gaddis et al and is found
**                on page 607
*********************************************************************/
string binarySearch(int inputArr[], int targetNum, int size)
{
    int first = 0,
        last = size - 1,
        middle,
        position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;

        // If the current value is the target then return found
        if (inputArr[middle] == targetNum)
        {
            found == true;
            return "target value found";
        }

        // Or check the higher value half
        else if (inputArr[middle] > targetNum)
        {
            last = middle - 1;
        }

        // Or check the lower value half
        else
        {
            first = middle + 1;
        }
    }

    // Otherwise the loop ends and return not found
    return "target value not found";
}