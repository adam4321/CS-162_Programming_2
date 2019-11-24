/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
** Description:    File that implements the Medusa derived class 
*********************************************************************/

#include "Medusa.hpp"

/*********************************************************************
** Description:   Constructor function for the Medusa class derrived
**                from character. It takes the character's armor 
**                amount and strength amount as arguments for the 
**                base constructor 
*********************************************************************/
Medusa::Medusa() : Character()
{
    armor = 3;
    strength = 8;
    isMedusa = true;
}

/*********************************************************************
** Description:   Virtual method for the Medusa class for 
**                attacking the  other character
*********************************************************************/
int Medusa::attack()
{
    int rollOne = rand() % 6 + 1;
    int rollTwo = rand() % 6 + 1;
    int rollTotal = rollOne + rollTwo;

    cout << "Medusa attacks with a roll of " << rollTotal << endl;

    return  rollTotal;
}

/*********************************************************************
** Description:   Virtual method for Medusa derrived class that is
**                for defending the other character's attack. It takes
**                the other character's attack and whether the other 
**                character is Medusa as arguments
*********************************************************************/
void Medusa::defense(int inputAttack, bool inputMedusa)
{
    if (inputAttack == 12 && inputMedusa == true)
    {
        strength = 0;

        cout << endl;
        cout << "Medusa has been killed by Medusa's glare!";
        cout << endl << endl;
    }
    else
    {
        int roll = rand() % 6 + 1;

        cout << "Medusa defends with " << armor << " armor";
        cout << " and " << strength << " strength before the attack" << endl;
        cout << "Medusa defends with a roll of " << roll << endl;

        int damage = inputAttack - roll - armor;

        if (damage < 0)
        {
            damage = 0;
        }

        strength = strength - damage;

        cout << "Medusa has " << strength << " strength after the attack";
        cout << endl;

        if (strength <= 0)
        {
            cout << endl;
            cout << "Medusa has died!";
        }
    }
}