/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
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

    cout << "Barbarian attacks with a roll of " << rollTotal << endl;

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

        cout << endl;
        cout << "Barbarian has been killed by Medusa's glare!";
        cout << endl << endl;
    }
    else
    {
        int rollOne = rand() % 6 + 1;
        int rollTwo = rand() % 6 + 1;
        int rollTotal = rollOne + rollTwo;

        cout << "Barbarian defends with " << armor << " armor";
        cout << " and " << strength << " strength before the attack" << endl;
        cout << "Barbarian defends with a roll of " << rollTotal << endl;

        int damage = inputAttack - rollTotal - armor;

        if (damage < 0)
        {
            damage = 0;
        }

        strength = strength - damage;

        cout << "Barbarian has " << strength << " strength after the attack";
        cout << endl;

        if (strength <= 0)
        {
            cout << endl;
            cout << "The Barbarian has died!";
        }
    }
}