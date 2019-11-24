/***********************************************************************
** Program name:   Compare recursion and iteration
** Author:         Adam Wright
** Date:           6/2/2019
** Description:    Header file for the iterative fib class
***********************************************************************/

#ifndef ITERATIVEFIB_HPP
#define ITERATIVEFIB_HPP

class IterativeFib
{
public:
    IterativeFib(const unsigned long long int &n);
    virtual ~IterativeFib();
    void PrintFibonacci();
private:
    IterativeFib();
    unsigned long long int Fibonacci(const unsigned long long int &n);
    const unsigned long long int* n_;
};
#endif