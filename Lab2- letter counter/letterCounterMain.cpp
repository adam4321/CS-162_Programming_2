/*********************************************************************
** Program name:    Letter Counter
** Author:          Adam Wright
** Date:            4-12-2019
** Description:     Program that opens a file and takes in it's text 
**                  as input and then prints out a file for each 
**                  paragraph that stores a list of how frequently 
**                  each letter appears. Run the program by typing
**                  countLetters into the console and following the 
**                  prompts.
*********************************************************************/

#include "letterFunctions.hpp"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::ifstream;
using std::ofstream;


int main()
{
	int menuChoice;
	string userFileName;
	int occurrenceArray[26];

	// Prompt the user for a file
	cout << endl << endl;
	cout << "Welcome to the Letter Counter";
	cout << endl << endl;
	cout << "This program will ask for a file path and then calculate the" << endl;
	cout << "occurrence of each letter in each paragraph.";
	cout << endl << endl;
	cout << "Please enter the path of the file that you would like analyzed";
	cout << endl << endl;

    // Take in the file path and store it in userFileName
	getline(cin, userFileName);
	cout << endl;

	// Create an input filestream object
	ifstream infile;
	infile.open(userFileName);

    while (!infile.is_open())
    {
        cout << "Unable to access the entered file";
        cout << endl << endl;
        cout << "Type the file name again or" << endl;
        cout << "Press q to quit";
        cout << endl << endl;

        // Try again or press 2 to quit
        getline(cin, userFileName);
        cout << endl;

        infile.open(userFileName);

        // Request to quit by choosing 2
        if (userFileName == "q")
        {
            cout << "Letter counter quitting - Goodbye!" << endl << endl;
            return 0;
        }
    }

    // Read in the file and calculate the occurrence
    if (infile.is_open())
    {
        count_letters(infile, occurrenceArray);
    }

    // Close the input file
    infile.close();

    cout << "The output files have completed" << endl;
    cout << "They are ready for you to view";
    cout << endl << endl;
    cout << "Goodbye!";
    cout << endl << endl;

    return 0;
}