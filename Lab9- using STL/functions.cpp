/***********************************************************************
** Program name:   Template Library Containers
** Author:         Adam Wright
** Date:           5/27/2019
** Description:    File that implements the two functions included in
**                 main.
***********************************************************************/

#include "functions.hpp"

/*********************************************************************
** Description:   Function to print a simulation of a random buffer to
**                the screen. It takes the user entered number of 
**                rounds for the function to run, the percentage chance
**                an element will be added to the queue's rear and the
**                percentage chance that an element will be removed 
**                from the queue's front as arguments
*********************************************************************/
void randomBuffer(int inputRounds, int inputEnd, int inputFront)
{
    int i = 1;
    double averageBuffer = 0.0;
    queue<int> buffer;
    queue<int> printBuffer;

    // Run the buffer function for the user chosen amount
    while (i <= inputRounds)
    {
        int N = rand() % 1000 + 1;
        int randEnd = rand() % 100 + 1;
        int randFront = rand() % 100 + 1;

        if (randEnd <= inputEnd)
        {
            buffer.push(N);
        }

        if (!buffer.empty() && randFront <= inputFront)
        {
            buffer.pop();
        }

        averageBuffer = (averageBuffer * (i - 1.0) + buffer.size()) / i;

        // Print a copy of the buffer
        printBuffer = buffer;
        
        cout << "**************************" << endl;
        cout << "Round " << i << " buffer: ";

        while (!printBuffer.empty())
        {
            cout << printBuffer.front() << " ";
            printBuffer.pop();
        }

        // Print the length of the buffer
        cout << endl << endl;
        cout << "Buffer length: " << buffer.size();

        // Print the average buffer for this round
        cout << endl << endl;
        cout << "Average Buffer Length: " << averageBuffer;
        cout << endl << endl;

        i++;
    }
}

/*********************************************************************
** Description:   Function to return a palindrome that is created from
**                the user entered string. It takes one argument which
**                is the user entered string
*********************************************************************/
void palindrome(string inputString)
{
    string reverseString;
    stack<char> outputStack;

    // Fill the stack with the input string
    for (int i = 0; i < inputString.length(); i++)
    {
        outputStack.push(inputString[i]); 
    }

    // Print the string forward
    cout << inputString;

    // Pop the stack to get the string backwards
    for (int i = 0; i < inputString.length(); i++)
    {
        cout << outputStack.top();
        outputStack.pop();
    }
}