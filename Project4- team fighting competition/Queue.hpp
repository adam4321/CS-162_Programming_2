/***********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
** Description:    Header file for the Queue class
***********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdlib.h>
#include <iostream>
#include "Character.hpp"

using std::cout;
using std::endl;


struct QueueNode
{
    Character *val;
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
    void addBack(Character *val);
    Character* getFront();
    void removeFront();
    void deleteFront();
    void printQueue();
};
#endif