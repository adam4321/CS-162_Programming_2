/************************************************************************
** Program name:   Search Sort Lab
** Author:         Adam Wright
** Date:           5/21/2019
** Description:    Program that implements 2 search and 1 sort algorithms
**                 It can be run by typing searchSort into the console
**                 and following the prompts.
************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "algorithms.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::ofstream;

bool requireNumbers(string menuInputTest);


int main()
{
    int numArray[9];
    int earlyArray[10];
    int midArray[10];
    int endArray[10];
    string menuInputTest;
    bool onlyNumbers = false;
    int targetValue;

    // Get the array sizes to pass into the functions
    int numArrSize = *(&numArray + 1) - numArray;
    int zeroArrSize = *(&endArray + 1) - endArray;


    // Pull the values from the 1-9 text file
    ifstream inFile;
    inFile.open("num.txt");

    for (int i = 0; i < numArrSize; i++)
    {
        inFile >> numArray[i];
    }
    inFile.close();


    // Pull the values from the early zero text file
    inFile.open("early.txt");

    for (int i = 0; i < zeroArrSize; i++)
    {
        inFile >> earlyArray[i];
    }
    inFile.close();


    // Pull the values from the mid zero text file
    inFile.open("mid.txt");

    for (int i = 0; i < zeroArrSize; i++)
    {
        inFile >> midArray[i];
    }
    inFile.close();


    // Pull the values from the late zero text file
    inFile.open("end.txt");

    for (int i = 0; i < zeroArrSize; i++)
    {
        inFile >> endArray[i];
    }
    inFile.close();


    // Greet the user
    cout << endl << endl; 
    cout << "*******************" << endl;
    cout << "Welcome to Lab 8" << endl;
    cout << "*******************";
    cout << endl << endl;

    // Prompt for the target value => 1-9 in all / 10 in none / 0 in 3 of 4 
    onlyNumbers = false;

	while (onlyNumbers == false || targetValue < 0 || targetValue > 10)
	{
        cout << "What is the target value to search for?" << endl;
        cout << "Please enter a value between 0 and 10";
 		cout << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireNumbers(menuInputTest);
		targetValue = atoi(menuInputTest.c_str());
        cout << endl;
    }

    // Run simple search on the unsorted arrays and print found or not found
    cout << "*************************************************" << endl;
    cout << "Simple Search";
    cout << endl << endl;
    cout << "num.txt: " << simpleSearch(numArray, targetValue, numArrSize);
    cout << endl << endl;
    cout << "early.txt: " << simpleSearch(earlyArray, targetValue, zeroArrSize);
    cout << endl << endl;
    cout << "mid.txt: " << simpleSearch(midArray, targetValue, zeroArrSize);
    cout << endl << endl;
    cout << "end.txt: " << simpleSearch(endArray, targetValue, zeroArrSize);
    cout << endl << endl;

    // Sort the arrays, print the sorted values, ask for outfile name
    ofstream outFile;
    string userOutputFile;

    cout << "*********************************************" << endl;
    cout << endl << endl;


    // Save the sorted array of 1-9
    cout << "num.txt sorted: ";
    selectionSort(numArray, numArrSize);
    cout << endl << endl;
    cout << "Please enter an output file name to save to";
    cout << endl << endl;
    cin.clear();
    cin.ignore();
    getline(cin, userOutputFile);
    outFile.open(userOutputFile);

    for (int i = 0; i < numArrSize; i++)
    {
        outFile << numArray[i];
    }
    outFile.close();


    // Save the sorted array that had 0 early
    cout << endl << endl;
    cout << "early.txt sorted: ";
    selectionSort(earlyArray, zeroArrSize);
    cout << endl << endl;
    cout << "Please enter an output file name to save to";
    cout << endl << endl;
    getline(cin, userOutputFile);
    outFile.open(userOutputFile);

    for (int i = 0; i < zeroArrSize; i++)
    {
        outFile << earlyArray[i];
    }
    outFile.close();


    // Save the the array that had 0 in middle
    cout << endl << endl;
    cout << "mid.txt sorted: ";
    selectionSort(midArray, zeroArrSize);
    cout << endl << endl;
    cout << "Please enter an output file name to save to";
    cout << endl << endl;
    getline(cin, userOutputFile);
    outFile.open(userOutputFile);

    for (int i = 0; i < zeroArrSize; i++)
    {
        outFile << midArray[i];
    }
    outFile.close();


    // Save the array that had 0 at the end
    cout << endl << endl;
    cout << "end.txt sorted: ";
    selectionSort(endArray, zeroArrSize);
    cout << endl << endl;
    cout << "Please enter an output file name to save to";
    cout << endl << endl;
    getline(cin, userOutputFile);
    outFile.open(userOutputFile);

    for (int i = 0; i < zeroArrSize; i++)
    {
        outFile << endArray[i];
    }
    outFile.close();


    // Run binary search on the sorted arrays and print found or not found
    cout << endl << endl;
    cout << "*************************************************" << endl;
    cout << "Binary Search";
    cout << endl << endl;
    cout << "num.txt: " << binarySearch(numArray, targetValue, numArrSize);
    cout << endl << endl;
    cout << "early.txt: " << binarySearch(earlyArray, targetValue, zeroArrSize);
    cout << endl << endl;
    cout << "mid.txt: " << binarySearch(midArray, targetValue, zeroArrSize);
    cout << endl << endl;
    cout << "end.txt: " << binarySearch(endArray, targetValue, zeroArrSize);

    cout << endl << endl << endl;
    cout << "**********************" << endl;
    cout << "Program complete" << endl;
    cout << "**********************";
    cout << endl << endl;

    return 0;
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