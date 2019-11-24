/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    Header file for the University class
*********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Person.hpp"
#include "Student.hpp"
#include "Building.hpp"
#include "Instructor.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class University
{
protected:
    string name = "Oregon State University";
    Building **buildingArr = new Building*[2];
    Person **personArr = new Person*[2];
    Building *building;
    Person *student;
    Person *instructor;
public:
    University();
    ~University();
    void printBuildings();
    void printPeople();
    void chooseWorker();
};
#endif