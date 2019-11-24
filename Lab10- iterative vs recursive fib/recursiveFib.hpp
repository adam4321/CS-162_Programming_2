/***********************************************************************
** Program name:   Compare recursion and iteration
** Author:         Adam Wright
** Date:           6/2/2019
** Description:    Header file for the recursive fib class
***********************************************************************/

#ifndef RECURSIVEFIB_HPP
#define RECURSIVEFIB_HPP

class RecursiveFib
{
public:
    RecursiveFib(const unsigned long long int &n);
    virtual ~RecursiveFib();
    void PrintFibonacci();
private:
    RecursiveFib();
    unsigned long long int Fibonacci(const unsigned long long int &n);
    const unsigned long long int* n_;
};
#endif