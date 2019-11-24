/*********************************************************************
** Program name:   Fantasy Combat Tournament
** Author:         Adam Wright
** Date:           5/17/2019
** Description:    Header file for the Character base class 
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Character
{
protected:
    int armor;
    int strength;
    bool isMedusa = false;
    string type;
    string name;

public:
    Character();
    Character(int inputArmor, int inputStrength);
    virtual int attack() = 0;
    virtual void defense(int inputAttack, bool isMedusa) = 0;
    virtual void setStrength(int inputStrength);
    virtual int getStrength();
    virtual bool getMedusa();
    virtual string getType();
    virtual void setName(string inputName);
    virtual string getName();
};
#endif