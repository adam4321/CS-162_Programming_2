/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
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

    cout << "Harry Potter attacks with a roll of " << rollTotal << endl;

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

        cout << endl;
        cout << "Harry Potter has been killed by Medusa's glare!";
        cout << endl << endl;

        if (timesKilled == 0)
        {
            timesKilled = 1;
            strength = 20;

            cout << endl;
            cout << "Hogwarts has stepped in and Harry has recovered!!!";
            cout << endl << endl;
        }
    }
    else
    {
        int rollOne = rand() % 6 + 1;
        int rollTwo = rand() % 6 + 1;
        int rollTotal = rollOne + rollTwo;

        cout << "Harry Potter defends with " << armor << " armor";
        cout << " and " << strength << " strength before the attack" << endl;
        cout << "Harry Potter defends with a roll of " <<  rollTotal << endl;

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

            cout << endl;
            cout << "Hogwarts has stepped in and Harry has recovered!!!";
            cout << endl << endl;           
        }

        cout << "Harry Potter has " << strength << " strength after the attack";
        cout << endl;

        if (strength <= 0)
        {
            cout << endl;
            cout << "Harry Potter has died!";
        }
    }
}