/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
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
}

/*********************************************************************
** Description:   Virtual method for the Vampire class for 
**                attacking the  other character
*********************************************************************/
int Vampire::attack()
{
    int roll = rand() % 12 + 1;

    cout << "Vampire attacks with a roll of " << roll << endl;

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

        cout << endl;
        cout << "Vampire has been killed by Medusa's glare!";
        cout << endl << endl;
    }
    else
    {
        int charm = rand() % 2;
        int roll = rand() % 6 + 1;

        cout << "Vampire defends with " << armor << " armor";
        cout << " and " << strength << " strength before the attack" << endl;
        cout << "Vampire defends with a roll of " << roll << endl;

        if (charm == 0)
        {
            cout << endl;
            cout << "Vampire has charmed his way out of the attack!";
            cout << endl << endl;
        }
        else 
        {
            int damage = inputAttack - roll - armor;

            if (damage < 0)
            {
                damage = 0;
            }

            strength = strength - damage;

            cout << "Vampire has " << strength << " strength after the attack";
            cout << endl;

            if (strength <= 0)
            {
                cout << endl;
                cout << "The Vampire has died!";
            }
        }    
    }
}
