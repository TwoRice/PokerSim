#include <iostream>
#include "Menu.h"
#include "PokerSim.cpp"

using namespace std;

void Menu::game(){

	PokerSim game;

}

void Menu::display(){

	cout << "1. Start" << endl;
	cout << "2. Quit" << endl;

}

void Menu::read(){

	int selection;

	do{

		display();
		cout << "Enter Selection : " << endl;
		cin >> selection;

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

Menu::Menu(){

	read();

}

int main(){

	Menu m;
	return 0;

}