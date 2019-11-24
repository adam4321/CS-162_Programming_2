/***********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
** Description:    File that implements the Queue class
***********************************************************************/

#include "Queue.hpp"

/*********************************************************************
** Description:   Constructor function for the Queue class. It takes 
**                the user entered value as it's argument.
*********************************************************************/
Queue::Queue()
{
    head = NULL;
};


/*********************************************************************
** Description:   Queue class destructor function to free the 
**                allocated heap memory when the program ends
*********************************************************************/
Queue::~Queue()
{
    // If the list is empty then do nothing
    if (isEmpty() == true)
    {
        return;
    }

    else
    {
        // Delete the front node until the Queue is empty
        QueueNode *ptr = head;

        do
        {
            QueueNode *node = ptr;

            ptr = ptr->next;
            delete node;

        } while (ptr != NULL && ptr != head);   
    }
}

/*********************************************************************
** Description:   Method that checks whether the queue is empty. It 
**                returns a bool 
*********************************************************************/
bool Queue::isEmpty()
{
    // If the head is null then there are no nodes
    if (head == NULL)
    {
        return true;
    }

    // Otherwise there are nodes in the queue
    else
    {
        return false;
    }
}

/*********************************************************************
** Description:   Method that adds a node to the back of the queue. It
**                takes a pointer to a Character object as it's argument
*********************************************************************/
void Queue::addBack(Character *val)
{
    // If there are no nodes then next and prev point to the current node
    if (isEmpty() == true)
    {
        QueueNode *node = new QueueNode;

        node->val = val;
        node->next = node;
        node->prev = node;
        head = node;
    }

    // Otherwise prev points to the last node and next points to the head
    else
    {
        QueueNode *last = head->prev;
        QueueNode *node = new QueueNode;
        
        node->val = val;
        node->next = head;
        head->prev = node;
        node->prev = last;
        last->next = node;
    }
}

/*********************************************************************
** Description:   Method that returns the first Character in the queue
*********************************************************************/
Character* Queue::getFront()
{
    // If the list is empty then print a message

    if (isEmpty() == true)
    {
        cout << "The Front is empty";
    }

    // Otherwise return the first node's value

    else
    {
        QueueNode *node = head;

        node->next;
        return node->val;
    }
}

/*********************************************************************
** Description:   Method that removes the front Character
*********************************************************************/
void Queue::removeFront()
{
    // If the list is empty then print a message
    if (isEmpty() == true)
    {
        cout << endl << endl;
        cout << "Can't remove Front is empty";
    }

    // Otherwise remove the front node
    else
    {
        // If only one node is left
        if (head->next == head)
        {
            delete head;
            head = NULL;
        }

        // More than one node left
        else
        {
            QueueNode *ptr = head;

            head = head->next;
            head->prev = ptr->prev;
            ptr->prev->next = head;
            delete ptr;
        }
    }
}

/*********************************************************************
** Description:   Method that deletes the front node and it's value.
**                This is for freeing the Characters at the end of the
**                pointers. A hard fought victory!
*********************************************************************/
void Queue::deleteFront()
{
    // If the list is empty then print a message
    if (isEmpty() == true)
    {
        cout << endl << endl;
        cout << "Can't remove Front is empty";
    }

    // Otherwise remove the front node
    else
    {
        // If only one node is left
        if (head->next == head)
        {
            delete head;
            head = NULL;
        }

        // More than one node left
        else
        {
            QueueNode *ptr = head;

            head = head->next;
            head->prev = ptr->prev;
            ptr->prev->next = head;
            delete ptr->val;
            delete ptr;
        }
    }
}

/*********************************************************************
** Description:   Method that prints the Queue
*********************************************************************/
void Queue::printQueue()
{
    // If the list is empty then print a message
    if (isEmpty() == true)
    {
        cout << "The list is empty";
    }

    // Otherwise print the queue
    else
    {
        QueueNode *node = head;

        if (head != NULL)
		{
			do
			{
				cout << node->val->getName() << " ";
				node = node->next;

			}while (node != NULL && node != head);
        }
    }
}