/***********************************************************************
** Program name:   Compare recursion and iteration
** Author:         Adam Wright
** Date:           6/2/2019
** Description:    File that implements the recursive fib class. It's 
**                 implementation is based on the source code by 
**                 joseph.arul83@gmail.com on https://www.codeproject.com
**                 /tips/109443/fibonacci-recursive-and-non-recursive-c
***********************************************************************/

#include "recursiveFib.hpp"
#include <iostream>

/*********************************************************************
** Description:   Default constructor function for the iterative  
**                fibonacci class
*********************************************************************/
RecursiveFib::RecursiveFib() {}

/*********************************************************************
** Description:   Constructor function for the iterative fibonacci 
**                class
*********************************************************************/
RecursiveFib::RecursiveFib(const unsigned long long int &n):n_(&n) {}

/*********************************************************************
** Description:   Destructor function for the iterative fibonacci 
**                class
*********************************************************************/
RecursiveFib::~RecursiveFib() {}

/*********************************************************************
** Description:   Function that runs the Fibonacci algorithm 
**                recursively. It takes a 64 bit int as a parameter 
**                and returns a 64 bit int
*********************************************************************/
unsigned long long int RecursiveFib::Fibonacci(const unsigned long long int &n)
{
  	if (n == 0)
  		return 0;
  	else if(n == 1)
  		return 1;
  	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

/*********************************************************************
** Description:   Function to print the nth Fibonacci number
*********************************************************************/
void RecursiveFib::PrintFibonacci()
{
    const unsigned long long int result = Fibonacci(*n_);
    std::cout << *n_ << "th fibonacci Number: " << result << std::endl;
}