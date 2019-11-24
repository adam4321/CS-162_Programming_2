/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    Header file for the Building class
*********************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Building
{
protected:
    string name;
    string size;
    string address;
public:
    Building();
    Building(string, string, string);
    void printBuildingInfo();
};
#endif        