/***********************************************************************
** Program name:   Compare recursion and iteration
** Author:         Adam Wright
** Date:           6/2/2019
** Description:    File that implements the iterative fib class. It's
**                 implementation is based on the source code by 
**                 joseph.arul83@gmail.com on https://www.codeproject.com
**                 /tips/109443/fibonacci-recursive-and-non-recursive-c
***********************************************************************/

#include "iterativeFib.hpp"
#include <iostream>

/*********************************************************************
** Description:   Default constructor function for the iterative  
**                fibonacci class
*********************************************************************/
IterativeFib::IterativeFib() {}

/*********************************************************************
** Description:   Constructor function for the iterative fibonacci 
**                class
*********************************************************************/
IterativeFib::IterativeFib(const unsigned long long int &n):n_(&n) {}

/*********************************************************************
** Description:   Destructor function for the iterative fibonacci 
**                class
*********************************************************************/
IterativeFib::~IterativeFib() {}

/*********************************************************************
** Description:   Function that runs the Fibonacci algorithm 
**                iteratively. It takes a 64 bit int as a parameter 
**                and returns a 64 bit int
*********************************************************************/
unsigned long long int IterativeFib::Fibonacci(const unsigned long long int &n)
{
    unsigned long long int first = 0;
    unsigned long long int second = 1;
    unsigned long long int counter = 2;

    while(counter < n)
    {
        unsigned long long int temp = second;
        second = first + second;
        first = temp;
        ++counter;
    }

    if (n == 0)
        return 0;
    else
        return first + second;
}

/*********************************************************************
** Description:   Function to print the nth Fibonacci number
*********************************************************************/
void IterativeFib::PrintFibonacci()
{
    const unsigned long long int result = Fibonacci(*n_);
    std::cout << *n_ << "th fibonacci Number: " << result << std::endl;
}