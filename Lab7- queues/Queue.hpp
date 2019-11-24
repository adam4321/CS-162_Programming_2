/***********************************************************************
** Program name:   Queue Lab
** Author:         Adam Wright
** Date:           5/15/2019
** Description:    Header file for the Queue class
***********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;


struct QueueNode
{
    int val;
    QueueNode *next;
    QueueNode *prev;
};

class Queue
{
private:
    QueueNode *head;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void addBack(int val);
    int getFront();
    void removeFront();
    void printQueue();
};
#endif