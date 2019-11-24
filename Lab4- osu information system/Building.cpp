/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    File that implements the Building class
*********************************************************************/

#include "Building.hpp"

/*********************************************************************
** Description:    Default constructor for the Building class
*********************************************************************/
Building::Building() {}

/*********************************************************************
** Description:    Constructor for the Building class that takes 3 
**                 strings as arguments. They are the building name
**                 building size and the building address.
*********************************************************************/
Building::Building(string inputName, string inputSize, string inputAddress)
{
    name = inputName;
    size = inputSize;
    address = inputAddress;
}

/*********************************************************************
** Description:    Function that prints a building's information
*********************************************************************/
void Building::printBuildingInfo()
{
    cout << "Name:     " << name << endl;
    cout << "Size:     " << size << endl;
    cout << "Address:  " << address << endl;
}
