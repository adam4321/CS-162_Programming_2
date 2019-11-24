/***********************************************************************
** Program name:   Predator Prey simulation
** Author:         Group 16
** Date:           5/3/2019
** Description:    File that implements the Doodlebug derived class
***********************************************************************/

#include "Doodlebug.hpp"

/*********************************************************************
** Description:   Constructor that initializes a Doodlebug object
*********************************************************************/
Doodlebug::Doodlebug(int inputX, int inputY) : Critter()
{
    x = inputX;
    y = inputY;
    symbol = 'X';
    stepsSurvived = 0;
    starve = 0;
}

/**********************************************************************
** Description:   Function that moves a Doodlebug. It takes a reference
**                to the board array as it's argument
**********************************************************************/
void Doodlebug::move(Critter ***&inputArray)
{
    // Eat an Ant if there is one at a cardinal direction

    // Up
    if (x > 0 && inputArray[x - 1][y] != NULL && 
        inputArray[x - 1][y]->getSymbol() == 'O')
    {
        delete inputArray[x - 1][y];
        inputArray[x - 1][y] = inputArray[x][y];
        inputArray[x][y] = NULL;
        x -= 1;
        starve = 0;
        stepsSurvived++;
    }

    // Left
    else if (y > 0 && inputArray[x][y - 1] != NULL &&
            inputArray[x][y - 1]->getSymbol() == 'O')
    {
        delete inputArray[x][y - 1];
        inputArray[x][y - 1] = inputArray[x][y];
        inputArray[x][y] = NULL;
        y -= 1;
        starve = 0;
        stepsSurvived++;
    }

    // Down
    else if (x < 19 && inputArray[x + 1][y] != NULL &&
            inputArray[x + 1][y]->getSymbol() == 'O')
    {
        delete inputArray[x + 1][y];
        inputArray[x + 1][y] = inputArray[x][y];
        inputArray[x][y] = NULL;
        x += 1;
        starve = 0;
        stepsSurvived++;
    }

    // Right
    else if (y < 19 && inputArray[x][y + 1] != NULL &&
            inputArray[x][y + 1]->getSymbol() == 'O')
    {
        delete inputArray[x][y + 1];
        inputArray[x][y + 1] = inputArray[x][y];
        inputArray[x][y] = NULL;
        y += 1;
        starve = 0;
        stepsSurvived++;
    }

    // If no Ant then just move to an empty space
    else
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

        starve++;
        stepsSurvived++;
    }
}

/**********************************************************************
** Description:   Function that implements the Doodlebug's breeding. It
**                takes a reference to the board array as it's argument
**********************************************************************/
void Doodlebug::breed(Critter ***&inputArray)
{
    if (stepsSurvived > 0 && stepsSurvived % 8 == 0)
    {
        // Up
        if (x > 0 && inputArray[x - 1][y] == NULL)
        {
            inputArray[x - 1][y] = new Doodlebug(x - 1, y);
        }

        // Left
        else if (y > 0 && inputArray[x][y - 1] == NULL)
        {
            inputArray[x][y - 1] = new Doodlebug(x, y - 1);
        }

        // Down
        else if (x < 19 && inputArray[x + 1][y] == NULL)
        {
            inputArray[x + 1][y] = new Doodlebug(x + 1, y);
        }

        // Right
        else if (y < 19 && inputArray[x][y + 1] == NULL)
        {
            inputArray[x][y + 1] = new Doodlebug(x, y + 1);
        }
    }
}

/*********************************************************************
** Description:   Getter function for Doodlebug class
*********************************************************************/
int Doodlebug::getStarved()
{
    return starve;
}