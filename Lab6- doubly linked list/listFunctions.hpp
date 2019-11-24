/***********************************************************************
** Program name:   Doubly Linked List
** Author:         Adam Wright
** Date:           5/7/2019
** Description:    Header file for the List class
***********************************************************************/

#ifndef LISTFUNCTIONS_HPP
#define LISTFUNCTIONS_HPP

#include "Node.hpp"

class List
{
private:
    int nodeCount;
    Node *head;
    Node *tail;
public:
    List();
    ~List();
    void addToHead(int inputVal);
    void addToTail(int inputVal);
    void deleteHead();
    void deleteTail();
    void printReverse();
    void print();
    void getHead();
    void getTail();
    void populate();
};
#endif