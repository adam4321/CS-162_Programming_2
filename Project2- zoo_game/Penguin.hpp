/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    Header file for the Penguin class
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"


class Penguin : public Animal
{
public:
    Penguin();
    Penguin(int);
};
#endif