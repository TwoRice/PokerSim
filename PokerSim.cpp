#include <iostream>
#include "PokerSim.h"
#include "Genio.cpp"


using namespace std;

void PokerSim::setPlayers(){

	int chips;
	int noOfPlayers;
	string name;
	bool validName;

	while(true){

		cout << "Please enter number of Starting Chips" << endl;
		chips = Genio::readInt();
		if(chips > 0){break;}

		cout << "Please enter a value greater than 0" << endl;

	}

	while(true){

		cout << "Please enter number of Players: " << endl;
		noOfPlayers = Genio::readInt();
		if(noOfPlayers > 0 && noOfPlayers <= 10){break;}

		cout << "Please enter a value between 1 and 10" << endl;

	}

	for(int i = 0; i < noOfPlayers; i++){

		do{

			validName = true;
			cout << "Enter Player " << i+1 << "'s Name: " << endl;
			getline(cin, name);
			name = Genio::strToLower(name);
			for(int j = 0; j < i; j++){

				if(players.at(j).getName() == name){

					cout << "Duplicate name" << endl;
					validName = false;
					break;

				}

			}


		}while(validName == false);
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
				cout << "Currently on table: " << current_table << endl;
				cout << "Minimum to raise: " << min_raise << endl;
				cout << "Available: " << players.at(i).getChips() << endl;
				int to_bet;
				cout << "Enter amount to raise: " << endl;
				cin >> to_bet;
				players.at(i).bet(to_bet);
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
	this->current_table = 0;
	setPlayers();
	begin();
}

