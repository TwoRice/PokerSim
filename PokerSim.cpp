#include <iostream>
#include "PokerSim.h"

using namespace std;

void PokerSim::setPlayers(){

	int chips;
	int num;
	string name;

	cout << "Please enter number of Starting Chips" << endl;
	cin >> chips;
	cout << "Starting Chips set to: " << chips << endl;

	cout << "Please enter number of Players: " << endl;
	cin >> num;

	for(int i = 0; i < num; i++){

		cout << "Enter Player" << i << "'s Name: " << endl;
		cin >> name;
		Player temp(name, chips);
		players.push_back(temp);
	}

}

void PokerSim::begin() {
	for (int i = 0; i < players.size(); i++) {
		string name = players.at(i).getName();
		cout << name << ": Make selection.." << endl;
		cout << "[C]heck" << endl;
		cout << "[F]old" << endl;
		cout << "[R]aise" << endl;

		char selection;
		cin >> selection;
		switch(selection) {
			case 'c':
			case 'C':

				break;
			case 'f':
			case 'F':

				break;
			case 'r':
			case 'R':

				break;
			default:
				cout << "ERROR: Invalid selection." << endl;
				break;
		}
		// check - don't bet
		// call - match bet
		// fold - out
		// raise - increase bet
	}
}

PokerSim::PokerSim() {
	setPlayers();
	begin();
}

