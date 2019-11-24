/*************************************************************************
** Program name:   Predator Prey simulation
** Author:         Group 16
** Date:           5/3/2019
** Description:    File that implements the Ant class derived from critter
*************************************************************************/

#include "Ant.hpp"

/*********************************************************************
** Description:   Constructor that initializes an Ant object
*********************************************************************/
Ant::Ant(int inputX, int inputY) : Critter()
{
    x = inputX;
    y = inputY;
    symbol = 'O';
    stepsSurvived = 0;
}

/**********************************************************************
** Description:   Function that moves an Ant. It takes a reference
**                to the board array as it's argument
**********************************************************************/
void Ant::move(Critter ***&inputArray)
{
    int randomNumber = rand() % 4;

    // Up
    if (randomNumber == 0 && x > 0)
    {
        if (inputArray[x - 1][y] == NULL)
        {
            inputArray[x - 1][y] = inputArray[x][y];
            inputArray[x][y] = NULL;
            x -= 1;
        }
    }

    // Left
    else if (randomNumber == 1 && y > 0)
    {
        if (inputArray[x][y - 1] == NULL)
        {
            inputArray[x][y - 1] = inputArray[x][y];
            inputArray[x][y] = NULL;
            y -= 1;
        }
    }

    // Down
    else if (randomNumber == 2 && x < 19)
    {
        if (inputArray[x + 1][y] == NULL)
        {
            inputArray[x + 1][y] = inputArray[x][y];
            inputArray[x][y] = NULL;
            x += 1;
        }
    }

    // Right
    else if (randomNumber == 3 && y < 19)
    {
        if (inputArray[x][y + 1] == NULL)
        {
            inputArray[x][y + 1] = inputArray[x][y];
            inputArray[x][y] = NULL;
            y += 1;
        }
    }
    stepsSurvived++;
}

/*********************************************************************
** Description:   Function that implements the Ant's breeding. It takes
**                a reference to the board array as it's argument
*********************************************************************/
void Ant::breed(Critter ***&inputArray)
{
    if (stepsSurvived > 0 && stepsSurvived % 3 == 0)
    {
        // Up
        if (x > 0 && inputArray[x - 1][y] == NULL)
        {
            inputArray[x - 1][y] = new Ant(x - 1, y);
        }

        // Left
        else if (y > 0 && inputArray[x][y - 1] == NULL)
        {
            inputArray[x][y - 1] = new Ant(x, y - 1);
        }

        // Down
        else if (x < 19 && inputArray[x + 1][y] == NULL)
        {
            inputArray[x + 1][y] = new Ant(x + 1, y);
        }

        // Right
        else if (y < 19 && inputArray[x][y + 1] == NULL)
        {
            inputArray[x][y + 1] = new Ant(x, y + 1);
        }
    }
}
