/***********************************************************************
** Program name:   Doubly Linked List
** Author:         Adam Wright
** Date:           5/7/2019
** Description:    Header file for the Node class
***********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

class Node
{
private:
    int val;
    Node *next;
    Node *prev;
public:
    Node(int inputNum);
    void setNext(Node *inputNext);
    void setLast(Node *inputPrev);
    void setInt(int inputVal);
    Node *getNext();
    Node *getLast();
    int getInt();
};
#endif