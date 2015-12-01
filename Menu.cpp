#include <iostream>
#include "Menu.h"
#include "Player.cpp"
#include "PokerSim.cpp"

using namespace std;

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
				break;

			case 2:
			
				cout << "Exiting Program" << endl;
				break;

			default:
			
				cout << "Invalid Selection" << endl;
				breeak;		

		}

	}while(selection != 2);

}

int main(){

	read();
	return 0;

}