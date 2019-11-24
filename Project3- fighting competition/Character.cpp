/*********************************************************************
** Program name:   Fantasy Combat Game
** Author:         Adam Wright
** Date:           5/3/2019
** Description:    File for the Base class that implements a character
*********************************************************************/

#include "Character.hpp"

/*********************************************************************
** Description:   Default constructor for character base class 
*********************************************************************/
Character::Character() {}

/*********************************************************************
** Description:   Constructor function for the character base class. 
**                It takes the character's armor amount and strength 
**                amount as arguments from the derived constructor 
*********************************************************************/
Character::Character(int inputArmor, int inputStrength)
{
    armor = inputArmor;
    strength = inputStrength;
}

/*********************************************************************
** Description:   Pure virtual method for character base class that is
**                for attacking the  other character
*********************************************************************/
int Character::attack()
{
    return 0;
}

/*********************************************************************
** Description:   Pure virtual method for character base class that is
**                for defending the other character's attack. It takes
**                the other character's attack and whether the other 
**                character is Medusa as arguments
*********************************************************************/
void Character::defense(int inputAttack, bool isMedusa) {}

/*********************************************************************
** Description:   Getter functions for the character base class 
*********************************************************************/
int Character::getStrength()
{
    return strength;
}

bool Character::getMedusa()
{
    return isMedusa;
}