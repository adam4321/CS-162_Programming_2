/*********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
** Description:    File that implements the Barbarian derived class 
*********************************************************************/

#include "Blue_Men.hpp"

/*********************************************************************
** Description:   Constructor function for the Blue_men class derrived
**                from character. It takes the character's armor 
**                amount and strength amount as arguments for the 
**                base constructor 
*********************************************************************/
Blue_Men::Blue_Men() : Character()
{
    armor = 3;
    strength = 12;
    type = "Blue_men";
}

/*********************************************************************
** Description:   Virtual method for the Blue_men class for 
**                attacking the  other character
*********************************************************************/
int Blue_Men::attack()
{
    int rollOne = rand() % 10 + 1;
    int rollTwo = rand() % 10 + 1;
    int rollTotal = rollOne + rollTwo;

    return  rollTotal;
}

/*********************************************************************
** Description:   Virtual method for Blue_men derrived class that is
**                for defending the other character's attack. It takes
**                the other character's attack and whether the other 
**                character is Medusa as arguments
*********************************************************************/
void Blue_Men::defense(int inputAttack, bool inputMedusa)
{
    int rollTotal;

    if (inputAttack == 12 && inputMedusa == true)
    {
        strength = 0;
    }

    else
    {
        if (strength > 8)
        {
            int rollOne = rand() % 6 + 1;
            int rollTwo = rand() % 6 + 1;
            int rollThree = rand() % 6 + 1;
            rollTotal = rollOne + rollTwo + rollThree;
        }

        else if (strength > 4)
        {
            int rollOne = rand() % 6 + 1;
            int rollTwo = rand() % 6 + 1;
            rollTotal = rollOne + rollTwo;
        }

        else
        {
            rollTotal = rand() % 6 + 1;
        }

        int damage = inputAttack - rollTotal - armor;

        if (damage < 0)
        {
            damage = 0;
        }

        strength = strength - damage;
    }
}