<<<<<<< HEAD
#include <iostream>
#include "Menu.h"
#include "Player.cpp"
#include "PokerSim.cpp"

using namespace std;

Menu::Menu(){
=======
class Menu {
public:
	Menu() {
		display();
	}

private:
	void display() {

	}
>>>>>>> 18715b53e4c47ca1121814eaf1aec58dc464cf01


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