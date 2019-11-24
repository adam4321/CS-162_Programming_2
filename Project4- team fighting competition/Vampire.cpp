/*********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
** Description:    File that implements the Vampire derived class 
*********************************************************************/

#include "Vampire.hpp"

/*********************************************************************
** Description:   Constructor function for the Vampire class derrived
**                from character. It takes the character's armor 
**                amount and strength amount as arguments for the 
**                base constructor 
*********************************************************************/
Vampire::Vampire() : Character()
{
    armor = 1;
    strength = 18;
    type = "Vampire";
}

/*********************************************************************
** Description:   Virtual method for the Vampire class for 
**                attacking the  other character
*********************************************************************/
int Vampire::attack()
{
    int roll = rand() % 12 + 1;

    return  roll;
}

/*********************************************************************
** Description:   Virtual method for Vampire derrived class that is
**                for defending the other character's attack. It takes
**                the other character's attack and whether the other 
**                character is Medusa as arguments
*********************************************************************/
void Vampire::defense(int inputAttack, bool inputMedusa)
{
    if (inputAttack == 12 && inputMedusa == true)
    {
        strength = 0;
    }

    else
    {
        int charm = rand() % 2;
        int roll = rand() % 6 + 1;


        if (charm == 0)
        {

        }
        
        else 
        {
            int damage = inputAttack - roll - armor;

            if (damage < 0)
            {
                damage = 0;
            }

            strength = strength - damage;
        }    
    }
    
}
