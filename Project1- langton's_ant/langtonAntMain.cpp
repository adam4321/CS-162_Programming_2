/*********************************************************************
** Program name:   Langton's Ant
** Author:         Adam Wright
** Date:           4/8/2019
** Description:    Program that implements the famous problem Langton's
**                 ant. It can be run by typing langtonAnt on the
**                 console and following the prompts.
*********************************************************************/

#include "Menu.hpp"
#include "Ant.hpp"

int main()
{
	// Wrap the program in a do while loop to allow restarting
	bool restart = true;

	do
	{
		// Create a menu instance
		Menu menu;

		// Create an ant instance and pass in the menu values
		Ant ant(menu);

	} while (restart == true);

	return 0;
}