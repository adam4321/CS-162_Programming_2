/*********************************************************************
** Program name:   OSU Information System
** Author:         Adam Wright
** Date:           4/25/2019
** Description:    File that implements the University class
*********************************************************************/

#include "University.hpp"

/*********************************************************************
** Description:    Default constructor for the University class that 
**                 manually creates the necessary objects for the 
**                 program
*********************************************************************/
University::University()
{
    building = new Building("Adams Hall", "11,168", "606 SW 15th ST");
    buildingArr[0] = building;

    building = new Building("Aero Engineering Lab", "3,637", "852 SW 30TH ST");
    buildingArr[1] = building;

    student = new Student("Bobby", 20 , 3.5);
    personArr[0] = student;

    instructor = new Instructor("Dr.Stelmach" , 42, 4.5);
    personArr[1] = instructor;
}

/*********************************************************************
** Description:    Destructor function for the University class that 
**                 frees all of the heap allocated memory
*********************************************************************/
University::~University()
{
    delete personArr[0];
    delete personArr[1];
    delete []personArr;
    delete buildingArr[0];
    delete buildingArr[1];
    delete []buildingArr;
}

/*********************************************************************
** Description:    Function that prints all of the existing buildings
*********************************************************************/
void University::printBuildings()
{
    cout << "*********************************"<< endl;
    cout << "At " << name << endl;
    cout << "These are the buildings on campus" << endl;
    cout << "*********************************"<< endl;
    cout << endl << endl;
    
    // Print building 1
    buildingArr[0]->printBuildingInfo();
    cout << endl << endl;

    // Print building 2
    buildingArr[1]->printBuildingInfo();
}

/*********************************************************************
** Description:    Function that prints all of the existing people
*********************************************************************/
void University::printPeople()
{
    cout << "*********************************"<< endl;
    cout << "At " << name << endl;
    cout << "These are the people on campus" << endl;
    cout << "*********************************"<< endl;
    cout << endl << endl;
    
    // Print the student's stats
    cout << "Name:   ";
    personArr[0]->printName();
    cout << endl << "Age:    ";
    personArr[0]->printAge();
    cout << endl <<"Gpa:    ";
    personArr[0]->printGpa();
    cout << endl << endl;

    // Print the instructor's stats
    cout << endl << "Name:   ";
    personArr[1]->printName();
    cout << endl <<"Age:    ";
    personArr[1]->printAge();
    cout << endl << "Rating: ";
    personArr[1]->printRating();
}

/*********************************************************************
** Description:    Function that implements the menu choice 3 from 
**                 main that prints the do_work function for a 
**                 student and an instructor
*********************************************************************/
void University::chooseWorker()
{
    int menuChoice = 0;
	string inputTest;
    bool onlyNumbers = false;

    // While loop to validate user input of only 1 or 2 
    onlyNumbers = false;

    while (onlyNumbers == false || menuChoice != 1 && menuChoice != 2)                          
    {
        cout << endl << endl;
        cout << "Press 1 to query person 1" << endl;
        cout << "Press 2 to query person 2" << endl;
        cout << endl << endl;
        cin >> inputTest;
        onlyNumbers = inputTest.find_first_not_of("0123456789") == string::npos;
        menuChoice = atoi(inputTest.c_str());
        cout << endl;
    }

    // Print Student do_work result
    if (menuChoice == 1)
    {
        personArr[0]->do_work();    
    }

    // Print Instructor do_work result
    if (menuChoice == 2)
    {
        personArr[1]->do_work();      
    }
}