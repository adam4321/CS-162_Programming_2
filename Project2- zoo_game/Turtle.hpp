/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    Header file for the Turtle class
*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"


class Turtle : public Animal
{
public:
    Turtle();
    Turtle(int);
};
#endif