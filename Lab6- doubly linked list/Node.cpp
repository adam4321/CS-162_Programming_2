/***********************************************************************
** Program name:   Doubly Linked List
** Author:         Adam Wright
** Date:           5/7/2019
** Description:    File that implements the Node class
***********************************************************************/

#include "Node.hpp"

/*********************************************************************
** Description:   Constructor function for the Node class. It takes 
**                the user entered value as it's argument.
*********************************************************************/
Node::Node(int inputVal)
{
    val = inputVal;
    next = NULL;
    prev = NULL;
}

/*********************************************************************
** Description:   Getter and setter methods for the Node class
*********************************************************************/
void Node::setNext(Node *inputNext)
{
    next = inputNext;
}

void Node::setLast(Node *inputPrev)
{
    prev = inputPrev;
}

void Node::setInt(int inputVal)
{
    val = inputVal;
}

int Node::getInt()
{
    return val;
}

Node *Node::getNext()
{
    return next;
}

Node *Node::getLast()
{
    return prev;
}
