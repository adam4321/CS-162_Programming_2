/*********************************************************************
** Program name:    Letter Counter
** Author:          Adam Wright
** Date:            4-12-2019
** Description:     2 Functions to support the letter counter.  
*********************************************************************/

#include "letterFunctions.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

/*********************************************************************
** Description:  Function that takes in two arguments. An input 
**               filestream object by reference and a pointer 
**               to a 26 position array for the lower case alphabet.
**               The function loops through the ascii values for the 
**               lower case alphabet and increments a counter for the 
**               occurrence of each letter and sets the number into
**               the array that is passed in.
*********************************************************************/
void count_letters(ifstream &infile, int *occurrenceArray)
{
	string paragraph;

	// Take in one paragraph at a time from the input file
	while (getline(infile, paragraph))
	{
		// Loop over the 26 lower case letter ascii codes
		for (int j = 97; j < 123; j++)
		{
			int letterCounter = 0;

			// Set incoming paragraph letter to lower case
		    for (int i = 0; i < paragraph.length(); i++)
		    {
				int charInt;
			    paragraph[i] = tolower(paragraph[i]);
				charInt = int(paragraph[i]);

				// Count the occurrence of each letter
                if (charInt == j)
                {
                    letterCounter++;
                }
		    }

			// Print the occurrence to the array zero indexed
			occurrenceArray[j - 97] = letterCounter;
		}

		// Create an output filestreram object
		ofstream outfile;

		// Output the letters to the chosen output file
		output_letters(outfile, occurrenceArray);
	}
}

/*********************************************************************
** Description:  Function that is passed to the letter counter function
**               and takes in an output file object and a pointer to
**               a 26 position array for the lower case alphabet. It
**               asks the user for a file name to output to and it 
**               prints the letter of the alphabet and the occurance in
**               the current paragraph into out output file.
*********************************************************************/
void output_letters(ofstream &outfile, int *occurrenceArray)
{
	string userOutputFile;

	cout << "Please enter a filename for this paragraph's output values";
	cout << endl << endl;

	// Take in the file name for the output file
	getline(cin, userOutputFile);
	cout << endl;

	outfile.open(userOutputFile);

	// Print the lower case alphabet using their ascii codes and 
	// remove 97 from the array to print it starting from 0
	for (int i = 97; i < 123; i++)
	{
		outfile << (char)i << ": " << occurrenceArray[i - 97] << endl;
	}

	outfile.close();
}