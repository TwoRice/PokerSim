/**
* Author - Rory Magowan, James Neil, Daniel Brereton, Daniel Kinnaird, Shaun Falconer
* Version 1.0 3rd December 2015
*
*/#include <iostream>
#include "Menu.h"
#include "PokerSim.cpp"

using namespace std;

/**
* Method which creates an instance of the poker sumulation and runs it
*
*/
void Menu::game(){

	PokerSim game;

}

/**
* Method to display a simple text based menu to the user
*
*/
void Menu::display(){

	cout << "1. Start" << endl;
	cout << "2. Quit" << endl;

}

/**
* Method to handle the users input in the menu
*
*/
void Menu::read(){

	int selection;

	do{

		display();
		cout << "Enter Selection : " << endl;
		selection = Genio::readInt();
		switch(selection){

			case 1:
				game();
				break;

			case 2:
				cout << "Exiting Program" << endl;
				break;

			default:
				cout << "Invalid Selection" << endl;
				break;		

		}

	}while(selection != 2);

}

/**
* Constructor method for the menu class which runs the menu
*
*/
Menu::Menu(){

	read();

}

/**
* Main method where an instance of the menu is created and the program is run
*
* return - exit code 0
*/
int main(){

	Menu m;
	return 0;

}