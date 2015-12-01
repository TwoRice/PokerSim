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

		int min_raise = current_table - players.at(i).getCurrentBet();
		int available = players.at(i).getChips();

		if(min_raise > available) {
			cout << "ERROR: " << players.at(i).getName() << " doesn't have enough chips to continue; Folding.." << endl;
			players.at(i).fold();
		}
		if(players.at(i).isFolded()) {
			continue;
		}

		cout << players.at(i).getName() << ": Make selection.." << endl;
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
				players.at(i).fold();
				break;
			case 'r':
			case 'R':
				if()
				cout << "Currently on table: " << current_table << endl;
				cout << "Minimum to raise: " << min_raise << endl;
				cout << "Available: " players.at(i).getChips() << endl;
				players.at(i).
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
	this->current = 0;
	setPlayers();
	begin();
}

