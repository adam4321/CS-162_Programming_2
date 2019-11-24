/*********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
** Description:    File that implements the Barbarian derived class 
*********************************************************************/

#include "Barbarian.hpp"

/*********************************************************************
** Description:   Constructor function for the Barbarian class derrived
**                from character. It takes the character's armor 
**                amount and strength amount as arguments for the 
**                base constructor 
*********************************************************************/
Barbarian::Barbarian() : Character()
{
    armor = 0;
    strength = 12;
    type = "Barbarian";
}

/*********************************************************************
** Description:   Virtual method for the Barbarian class for 
**                attacking the  other character
*********************************************************************/
int Barbarian::attack()
{
    int rollOne = rand() % 6 + 1;
    int rollTwo = rand() % 6 + 1;
    int rollTotal = rollOne + rollTwo;

    return  rollTotal;
}

/*********************************************************************
** Description:   Virtual method for Barbarian derrived class that is
**                for defending the other character's attack. It takes
**                the other character's attack and whether the other 
**                character is Medusa as arguments
*********************************************************************/
void Barbarian::defense(int inputAttack, bool inputMedusa)
{
    if (inputAttack == 12 && inputMedusa == true)
    {
        strength = 0;
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
    }
}