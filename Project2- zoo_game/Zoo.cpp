/*********************************************************************
** Program name:   Zoo Tycoon
** Author:         Adam Wright
** Date:           4/21/2019
** Description:    Class that implements the Zoo
*********************************************************************/

#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"


/*********************************************************************
** Description:   Default constructor that initializes the Zoo
**                with the starting values for the first day by running
**                running the player through the initial menu
*********************************************************************/
Zoo::Zoo()
{
    bool onlyNumbers = false;
    string menuInputTest;
    int menuChoice = 0;
    int numTigers = 0;
    int numPenguins = 0;
    int numTurtles = 0;
    int tigerArrSize = 0;
    int penguinArrSize = 0;
    int turtleArrSize = 0;

    // Seed the random function
    srand(time(NULL));

    cout << endl << endl;
    cout << "*********************************************";
    cout << endl << endl;
    cout << "How many Tigers would you like to start with?";
    cout << endl << endl;
    cout << "They cost $10,000 each";
    cout << endl << endl;

    // While loops to validate integer input
	while (onlyNumbers == false || menuChoice != 1.0 && menuChoice != 2.0)
	{
		cout << "Press 1 to start with one Tiger" << endl;
		cout << "Press 2 to start with two Tigers";
		cout << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireOnlyNumbers(menuInputTest);
		menuChoice = atoi(menuInputTest.c_str());	
		this->numTigers = menuChoice;
		cout << endl;
    }

    cout << "*********************************************";
    cout << endl << endl;
    cout << "How many Penguins would you like to start with?";
    cout << endl << endl;
    cout << "They cost $1,000 each";
    cout << endl << endl;

    onlyNumbers = false;

	while (onlyNumbers == false || menuChoice != 1.0 && menuChoice != 2.0)
	{
		cout << "Press 1 to start with one Penguin" << endl;
		cout << "Press 2 to start with two Penguins";
		cout << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireOnlyNumbers(menuInputTest);
		menuChoice = atoi(menuInputTest.c_str());	
		this->numPenguins = menuChoice;
		cout << endl;
    }

    cout << "*********************************************";
    cout << endl << endl;
    cout << "How many Turtles would you like to start with?";
    cout << endl << endl;
    cout << "They cost $100 each";
    cout << endl << endl;

    onlyNumbers = false;

	while (onlyNumbers == false || menuChoice != 1.0 && menuChoice != 2.0)
	{
		cout << "Press 1 to start with one Turtle" << endl;
		cout << "Press 2 to start with two Turtles";
		cout << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireOnlyNumbers(menuInputTest);
		menuChoice = atoi(menuInputTest.c_str());	
		this->numTurtles = menuChoice;
		cout << endl;
    }
}

/*********************************************************************
** Description:   Member function that is called in main that uses the
**                current values to begin the zoo game. It runs the 
**                player through the game day by day.
*********************************************************************/
void Zoo::startGame()
{
    int endGame = 0;
    string menuInputTest;
    bool onlyNumbers = false;
    double moneyInBank = 100000;
    int currentDay = 1;
    tigerArrSize = 10;
    penguinArrSize = 10;
    turtleArrSize = 10;

    // Create the animal arrays
	tigerArr = new Tiger[tigerArrSize];
	penguinArr = new Penguin[penguinArrSize];
	turtleArr = new Turtle[turtleArrSize];

    moneyInBank = moneyInBank - (numTigers * 10000 + 
                                numPenguins * 1000 + 
                                numTurtles * 100);

    // While the player has money, let them choose to play a day
    do
    {
        // Age the animals at the start of the day
        for (int i = 0; i < numTigers; i++)
        {
            tigerArr[i].setAge(tigerArr[i].getAge() + 1);
        }
        for (int i = 0; i < numPenguins; i++)
        {
            penguinArr[i].setAge(penguinArr[i].getAge() + 1);
        }
        for (int i = 0; i < numTurtles; i++)
        {
            turtleArr[i].setAge(turtleArr[i].getAge() + 1);
        }
        

        // Feed the current animals
        if (numTigers != 0)
        {
            moneyInBank = moneyInBank - (numTigers * tigerArr[0].getBaseFoodCost());
        }
        if (numPenguins != 0)
        {
            moneyInBank = moneyInBank - (numPenguins * penguinArr[0].getBaseFoodCost());
        }
        if (numTurtles != 0)
        {
            moneyInBank = moneyInBank - (numTurtles * turtleArr[0].getBaseFoodCost());
        }

        // Display the current day
        cout << endl << endl;
        cout << "************************************";
        cout << endl << endl;
        cout << "Today is day " << currentDay << endl;
        
        // The day's random event
        int randomEvent = rand() % 4 + 1;

        if (randomEvent == 1)
        {
            kill();
        }
        else if (randomEvent == 2)
        {
            zooBoom();
        }
        else if (randomEvent == 3)
        {
            baby();
        }
        else if (randomEvent == 4)
        {
            // Create file stream objects for extra credit
            ofstream outfile;
            ifstream infile;

            cout << endl;
            outfile.open("messages.txt");

            outfile << "No good or bad news today";
            outfile.close();

            infile.open("messages.txt");
            char letter = infile.get();

            while (infile)
            {
                cout << letter;
                letter = infile.get();
            }
            infile.close();
            cout << endl;
        }
        
        cout << endl;
        cout << "****************************************";
        cout << endl << endl;

        // Calculate the day's profit
        moneyInBank = moneyInBank + (numTigers * tigerArr->getPayoff());
	    moneyInBank = moneyInBank + (numPenguins * penguinArr->getPayoff());
        moneyInBank = moneyInBank + (numTurtles * turtleArr->getPayoff());


        // Display the current bank balance and animal totals
        cout << "Your current balance in the bank is $" << moneyInBank;
        cout << endl << endl;
        cout << "Your current number of Tigers is " << numTigers << endl;
        cout << "Your current number of Penguins is " << numPenguins << endl;
        cout << "Your current number of Turtles is " << numTurtles;

        // Ask if the player would like to add an adult to the zoo
        onlyNumbers = false;

        while (onlyNumbers == false || menuChoice != 1.0 && menuChoice != 2.0)
        {
            cout << endl << endl;
            cout << endl << endl;
            cout << "Press 1 if you would like to buy an adult" << endl;
            cout << "animal to add to your zoo";
            cout << endl << endl;
            cout << "Press 2 if you don't want to add an animal";
            cout << endl << endl;
            cin >> menuInputTest;
            onlyNumbers = requireOnlyNumbers(menuInputTest);
            menuChoice = atoi(menuInputTest.c_str());
            cout << endl;
        }

        if (menuChoice == 1)
        {
            onlyNumbers = false;

	        while (onlyNumbers == false || menuChoice != 1.0 && menuChoice != 2.0 && menuChoice != 3.0)
	        {
		        cout << "Press 1 to add a Tiger" << endl;
		        cout << "Press 2 to add a Penguin" << endl;
                cout << "Press 3 to add a Turtle" << endl;
		        cout << endl << endl;
		        cin >> menuInputTest;
		        onlyNumbers = requireOnlyNumbers(menuInputTest);
		        menuChoice = atoi(menuInputTest.c_str());	
		        cout << endl;
            }

            if (menuChoice == 1)
            {
                addTiger(1);
                tigerArr[numTigers - 1].setAge(3);
            }
            if (menuChoice == 2)
            {
                addPenguin(1);
                penguinArr[numPenguins - 1].setAge(3);
            }
            if (menuChoice == 3)
            {
                addTurtle(1);
                turtleArr[numTurtles - 1].setAge(3);
            }
        }

        // If the player has money then ask if they want to continue playing
        if (moneyInBank > 0.0)
        {

        endGame = dayEndMenu();
        this->currentDay = currentDay++;
        }

    }while (endGame != 2 && moneyInBank > 0.0);

    // If the player is out of money then end the game
    if (endGame != 2)
    {
        cout << endl << endl;
        cout << "****************************************";
        cout << endl << endl;
        cout << "I'm afraid that you have gone bankrupt." << endl;
        cout << "This game is over...";
        cout << endl << endl;
        cout << "****************************************";
        cout << endl << endl;
    }
}

/*********************************************************************
** Description:   Second menu for after the day finishes. User selects
**                the menu choice of 1 or 2 to choose whether to end
**                or continue. It returns 1 to restart
*********************************************************************/
int Zoo::dayEndMenu()
{
    string menuInputTest;

	// Take in user input of either integer 1 or 2
    bool onlyNumbers = false;

	while (onlyNumbers == false || menuChoice != 1.0 && menuChoice != 2.0)
	{
	    cout << endl << "Would you like to play another day?";
	    cout << endl << endl;
	    cout << "Press 1 to Continue to the next day" << endl;
	    cout << "Press 2 to End This Game";
	    cout << endl << endl;
		cin >> menuInputTest;
		onlyNumbers = requireOnlyNumbers(menuInputTest);
		menuChoice = atoi(menuInputTest.c_str());	
		this->endGame = menuChoice;
		cout << endl;
    }

	// Request to quit by choosing 2 on the menu
	if (endGame == 2)
	{
        cout << endl << endl;
        cout << "************************************";
        cout << endl << endl;
		cout << "Ending game....";
        cout << endl << endl;
        cout << "************************************";
		cout << endl << endl;
		return 2;
	}

	// Request to continue by choosing 1 on the menu
	if (endGame == 1)
	{
		return 1;
	}
}

/*********************************************************************
** Description:    Function that takes an integer as an argument and 
**                 it creates that number's worth of new Tigers. It 
**                 checks to see if there is enough space in the 
**                 current array and if not it doubles the size.
*********************************************************************/
void Zoo::addTiger(int input)
{
	numTigers = numTigers + input;

	if (numTigers > tigerArrSize - 1)
	{
        tigerArrSize = tigerArrSize * 2;

	    int beforeInput = numTigers - input;
	    int* tempArr = new int[beforeInput];

	    for (int i = 0; i < beforeInput; i++)
	    {
		    tempArr[i] = tigerArr[i].getAge();
	    }
	    
        delete[] tigerArr;

	    tigerArr = new Tiger[tigerArrSize];

	    for (int i = 0; i < beforeInput; i++)
	    {
		    tigerArr[i].setAge(tempArr[i]);
	    }
        
        delete[] tempArr;
	}
	moneyInBank = moneyInBank - (tigerArr[0].getCost() * input);
}

/*********************************************************************
** Description:    Function that takes an integer as an argument and 
**                 it creates that number's worth of new Penguins. It 
**                 checks to see if there is enough space in the 
**                 current array and if not it doubles the size.
*********************************************************************/
void Zoo::addPenguin(int input)
{
	numPenguins = numPenguins + input;

	if (numPenguins > penguinArrSize - 1)
	{
        penguinArrSize = penguinArrSize * 2;

	    int beforeInput = numPenguins - input;
	    int* tempArr = new int[beforeInput];

	    for (int i = 0; i < beforeInput; i++)
	    {
		    tempArr[i] = penguinArr[i].getAge();
	    }
	    
        delete[] penguinArr;

	    penguinArr = new Penguin[penguinArrSize];

	    for (int i = 0; i < beforeInput; i++)
	    {
		    penguinArr[i].setAge(tempArr[i]);
	    }
        
        delete[] tempArr;
	}
	moneyInBank = moneyInBank - (penguinArr[0].getCost() * input);
}


/*********************************************************************
** Description:    Function that takes an integer as an argument and 
**                 it creates that number's worth of new Turtles. It 
**                 checks to see if there is enough space in the 
**                 current array and if not it doubles the size.
*********************************************************************/
void Zoo::addTurtle(int input)
{
	numTurtles = numTurtles + input;

	if (numTurtles > turtleArrSize - 1)
	{
        turtleArrSize = turtleArrSize * 2;

	    int beforeInput = numTurtles - input;
	    int* tempArr = new int[beforeInput];

	    for (int i = 0; i < beforeInput; i++)
	    {
		    tempArr[i] = turtleArr[i].getAge();
	    }
	    
        delete[] turtleArr;

	    turtleArr = new Turtle[turtleArrSize];

	    for (int i = 0; i < beforeInput; i++)
	    {
		    turtleArr[i].setAge(tempArr[i]);
	    }
        
        delete[] tempArr;
	}
	moneyInBank = moneyInBank - (turtleArr[0].getCost() * input);
}

/*********************************************************************
** Description:    Function that chooses a random number from 1-3 and 
**                 kills one of that type of animal if there is one
*********************************************************************/
void Zoo::kill()
{
    // Create file stream objects for extra credit
    ofstream outfile;
    ifstream infile;

    outfile.open("messages.txt");

    // Choose a random number between 1 and 3
    int randAnimal = rand() % 3 + 1;

    // Kill a Tiger
    if (randAnimal == 1)
    {
        if (numTigers > 0)
        {
            cout << endl << endl;
            outfile << "I'm afraid that a Tiger has died...";
            outfile.close();

            infile.open("messages.txt");
            char letter = infile.get();

            while (infile)
            {
                cout << letter;
                letter = infile.get();
            }
            infile.close();

            cout << endl << endl;
            tigerArr[numTigers - 1].setAge(0);
            numTigers--;
        }
    }

    // Kill a Penguin
    else if (randAnimal == 2)
    {
        if (numPenguins > 0)
        {
            cout << endl << endl;
            outfile << "I'm afraid that a Penguin has died...";
            outfile.close();

            infile.open("messages.txt");
            char letter = infile.get();

            while (infile)
            {
                cout << letter;
                letter = infile.get();
            }
            infile.close();

            cout << endl << endl;
            penguinArr[numPenguins - 1].setAge(0);
            numPenguins--;
        }
    }

    // Kill a Turtle
    else if (randAnimal == 3)
    {
        if (numTurtles > 0)
        {
            cout << endl << endl;
            outfile << "I'm afraid that a Turtle has died...";
            outfile.close();

            infile.open("messages.txt");
            char letter = infile.get();

            while (infile)
            {
                cout << letter;
                letter = infile.get();
            }
            infile.close();

            cout << endl << endl;
            turtleArr[numTurtles - 1].setAge(0);
            numTurtles--;
        }
    }
}

/*********************************************************************
** Description:    Function that chooses a random number from 250-500
**                 to be given as a bonus for the number of tigers in
**                 the zoo 
*********************************************************************/
void Zoo::zooBoom()
{
    // Create file stream objects for extra credit
    ofstream outfile;
    ifstream infile;

    outfile.open("messages.txt");
    int bonus = rand() % 500 + 250;

    if (bonus > 500)
    {
        bonus = 500;
    }

    bonus = numTigers * bonus;

    cout << endl << endl;
    outfile << "Today is your lucky day!!!" << endl;
    outfile << "Attendance is up and you have made $" << bonus << " extra!";

    outfile.close();

    infile.open("messages.txt");
    char letter = infile.get();

    while (infile)
    {
        cout << letter;
        letter = infile.get();
    }
    infile.close();

    cout << endl;

    moneyInBank = moneyInBank + bonus;
}

/*********************************************************************
** Description:    Function that chooses a number from 1-3 at random
**                 and then if that animal type has an adult, they 
**                 will have the correct number of babies
*********************************************************************/
void Zoo::baby()
{
    // Create file stream objects for extra credit
    ofstream outfile;
    ifstream infile;

    outfile.open("messages.txt");

    int currentAge;
    bool isAdult = false;
    int randAnimal = rand() % 3 + 1;
    int iterator = 0;

    // Add a baby Tiger
    if (randAnimal == 1)
    {
        while (!isAdult && iterator < numTigers && numTigers > 0)
        {
            currentAge = tigerArr[0].getAge();

            if (currentAge >= 3)
            {
                isAdult = true;
                cout << endl << endl;

                outfile << "Today you had a new baby Tiger!!!";
                outfile.close();

                infile.open("messages.txt");
                char letter = infile.get();

                while (infile)
                {
                    cout << letter;
                    letter = infile.get();
                }
                infile.close();

                cout << endl << endl;

                addTiger(1);
            }

            iterator++;
        }
    }

    // Add 5 baby Penguins
    else if (randAnimal == 2)
    {
        while (!isAdult && iterator < numPenguins && numPenguins > 0)
        {
            currentAge = penguinArr[0].getAge();

            if (currentAge >= 3)
            {
                isAdult = true;
                cout << endl << endl;

                outfile << "Today you had 5 new baby Penguins!!!";
                outfile.close();

                infile.open("messages.txt");
                char letter = infile.get();

                while (infile)
                {
                    cout << letter;
                    letter = infile.get();
                }
                infile.close();

                cout << endl << endl;

                addPenguin(5);
            }
            
            iterator++;
        }
    }

    // Add 10 baby Turtles
    else if (randAnimal == 3)
    {
        while (!isAdult && iterator < numTurtles && numTurtles > 0)
        {
            currentAge = turtleArr[0].getAge();

            if (currentAge >= 3)
            {
                isAdult = true;
                cout << endl << endl;

                outfile << "Today you had 10 new baby Turtles!";

                outfile.close();

                infile.open("messages.txt");
                char letter = infile.get();

                while (infile)
                {
                    cout << letter;
                    letter = infile.get();
                }
                infile.close();
                cout << endl << endl;

                addTurtle(10);
            }

            iterator++;
        }
    }
}

/*********************************************************************
** Description:   Function to make sure that only integers are being
**                passed and not characters or periods or spaces. It takes 
**                a string as input and returns true if it only contains
**                the numbers 0 - 9.
*********************************************************************/
bool Zoo::requireOnlyNumbers(string menuInputTest)
{
	return menuInputTest.find_first_not_of("0123456789") == string::npos;
}

/*********************************************************************
** Description:   Function to make sure that only numbers are being
**                passed and not characters or spaces. It takes 
**                a string as input and returns true if it only contains
**                the numbers 0 - 9 or periods to allow floats.
*********************************************************************/
bool Zoo::requireFloatNumbers(string menuInputTest)
{
	return menuInputTest.find_first_not_of(".0123456789") == string::npos;
}

/*********************************************************************
** Description:    Destructor function that frees the Animal arrays
*********************************************************************/
Zoo::~Zoo()
{
	delete[] tigerArr;
	delete[] penguinArr;
	delete[] turtleArr;
}