/*********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
** Description:    File that implements the Harry_Potter derived class 
*********************************************************************/

#include "Harry_Potter.hpp"

/*************************************************************************
** Description:   Constructor function for the Harry Potter class derrived
**                from character. It takes the character's armor 
**                amount and strength amount as arguments for the 
**                base constructor 
*************************************************************************/
Harry_Potter::Harry_Potter() : Character()
{
    armor = 0;
    strength = 10;
    type = "Harry Potter";
}

/*********************************************************************
** Description:   Virtual method for the Harry potter class for 
**                attacking the  other character
*********************************************************************/
int Harry_Potter::attack()
{
    int rollOne = rand() % 6 + 1;
    int rollTwo = rand() % 6 + 1;
    int rollTotal = rollOne + rollTwo;

    return  rollTotal;
}

/*********************************************************************
** Description:   Virtual method for Harry potter derrived class that is
**                for defending the other character's attack. It takes
**                the other character's attack and whether the other 
**                character is Medusa as arguments
*********************************************************************/
void Harry_Potter::defense(int inputAttack, bool inputMedusa)
{
    if (inputAttack == 12 && inputMedusa == true)
    {
        strength = 0;

        if (timesKilled == 0)
        {
            timesKilled = 1;
            strength = 20;
        }
    }

    else
    {
        int rollOne = rand() % 6 + 1;
        int rollTwo = rand() % 6 + 1;
        int rollTotal = rollOne + rollTwo;

        int damage = inputAttack - rollTotal - armor;

        if (damage < 0)
        {
            damage = 0;
        }

        strength = strength - damage;

        if (strength <= 0 && timesKilled == 0)
        {
            timesKilled = 1;
            strength = 20;         
        }
    }
}