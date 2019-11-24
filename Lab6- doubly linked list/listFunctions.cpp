/***********************************************************************
** Program name:   Doubly Linked List
** Author:         Adam Wright
** Date:           5/7/2019
** Description:    File that implements the List class
***********************************************************************/

#include "listFunctions.hpp"

/*********************************************************************
** Description:   List class constructor function 
*********************************************************************/
List::List()
{
    nodeCount = 0;
    head = NULL;
    tail = NULL;
};

/*********************************************************************
** Description:   List class destructor function to hopefully free the 
**                allocated heap memory when the program ends
*********************************************************************/
List::~List()
{
    Node *node = head;

    // Delete nodes until the node pointer finds null
    while (node != NULL)
    {
        Node *next = node->getNext();
        delete node;
        node = next;
    }
}

/*********************************************************************
** Description:   Method to add a node to the head of the list. It 
**                takes the user entered value as it's argument.
*********************************************************************/
void List::addToHead(int inputVal)
{
    Node *node = new Node(inputVal);

    // If this is the first node then the head and tail are the same
    if (nodeCount == 0)
    {
        head = node;
        tail = node;
        nodeCount++;
    }

    // If this isn't the first node then add to the front of the list
    else
    {
        head->setLast(node);
        node->setNext(head);
        head = node;
        nodeCount++;
    }
}

/*********************************************************************
** Description:   Method to add node to the tail of the list. It takes
**                the user entered value as it's argument.
*********************************************************************/
void List::addToTail(int inputVal)
{
    Node *node = new Node(inputVal);

    // If this is the first node then the head and tail are the same
    if (nodeCount == 0)
    {
        head = node;
        tail = node;
        nodeCount++;
    }

    // If this isn't the first node then add to the end of the list
    else
    {
        tail->setNext(node);
        node->setLast(tail);
        tail = node;
        nodeCount++;
    }
}

/*********************************************************************
** Description:   Method to delete the current head node
*********************************************************************/
void List::deleteHead()
{
    // Print a message if there are no nodes
    if (nodeCount == 0)
    {
        cout << endl << endl;
        cout << "Values must be added before they can be deleted";
    }
    else
    {
        Node* node = head;
        head = head->getNext();

        // If this is the last node then delete it
        if (head == NULL)
        {
            delete node;
            nodeCount--;
        }

        // If there are nodes then remove head node
        else
        {
            head->setLast(NULL);
            delete node;
            nodeCount--;
        }
    } 
}

/*********************************************************************
** Description:   Method to delete the current tail node
*********************************************************************/
void List::deleteTail()
{
    // Print a message if there are no nodes
    if (nodeCount == 0)
    {
        cout << endl << endl;
        cout << "Values must be added before they can be deleted";
    }
    else
    {
        Node* node = tail;
        tail = tail->getLast();

        // If this is the last node then decrement counter
        if (tail == NULL)
        {
            nodeCount--;
        }

        // If there are nodes then remove current tail node
        else
        {
            tail->setNext(NULL);
            delete node;
            nodeCount--;
        }
    } 
}

/*********************************************************************
** Description:   Method to print the list
*********************************************************************/
void List::print()
{        
    // Print a message if there are no nodes
    if (nodeCount == 0)
    {
        cout << "Please add values. The list is currently empty.";
    }

    // Pointer to head node and print until finding null
    else
    {
        cout << "Your linked list is: ";

        Node *pointer = head;

        while (pointer != NULL)
        {
            cout << pointer->getInt() << " ";
            pointer = pointer->getNext();
        }
    }
}

/*********************************************************************
** Description:   Method to print the list in reverse
*********************************************************************/
void List::printReverse()
{
    // Print a message if there are no nodes
    if (nodeCount == 0)
    {
        cout << "Please add values. The list is currently empty.";
    }

    // Pointer to tail node and print until hitting null 
    else
    {
        Node *pointer = tail;

        while (pointer != NULL)
        {
            cout << pointer->getInt() << " ";
            pointer = pointer->getLast();
        }
    }
}

/*********************************************************************
** Description:   Method to print the head value
*********************************************************************/
void List::getHead()
{
    // Print a message if there are no nodes
    if (nodeCount == 0)
    {
        cout << "Please add values. The list is currently empty.";
    }

    // If there are nodes then print the head value
    else
    {
        cout << head->getInt();
    }
}

/*********************************************************************
** Description:   Method to print the tail value
*********************************************************************/
void List::getTail()
{
    // Print a message if there are no nodes
    if (nodeCount == 0)
    {
        cout << "Please add values. The list is currently empty.";
    }

    // If there are nodes then print the tail value
    else
    {
        cout << tail->getInt();
    }   
}

/*********************************************************************
** Description:   Method to create an array from an included test file
*********************************************************************/
void List::populate()
{
    // Create an input filestream object
    int input;
    ifstream infile;
    infile.open("listValues.txt");

    // While values are still coming from the file, create node objects
    while (infile >> input)
    {
        Node *node = new Node(input);

        // If this is the first node then the head and tail are the same
        if (nodeCount == 0)
        {
            head = node;
            tail = node;
            nodeCount++;
        }

        // If this isn't the first node then add to the end of the list
        else
        {
            tail->setNext(node);
            node->setLast(tail);
            tail = node;
            nodeCount++;
        }
    }

    infile.close();
}