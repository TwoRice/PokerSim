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
	// for each player in vector <players>
	for (int i = 0; i < players.size(); i++) {

		// calculate the minimum amount the player needs to raise
		int min_raise = current_table - players.at(i).getCurrentBet();		
		int available = players.at(i).getChips();

		// if the player doesn't have enough to raise
		if(min_raise > available) {
			// display error message
			cout << "ERROR: " << players.at(i).getName() << " doesn't have enough chips to continue; Folding.." << endl;
			// fold the player
			players.at(i).fold();
		}
		// if the player is folded
		if(players.at(i).isFolded()) {
			// skip to next iteration
			continue;
		}

		// prompt for selection
		cout << "["players.at(i).getName() << "] Make selection.." << endl;
		cout << "[C]heck" << endl;
		cout << "[F]old" << endl;
		cout << "[R]aise" << endl;

		// get selection
		char selection;
		cin >> selection;
		switch(selection) {
			// check
			case 'c':
			case 'C':
				break;
			// fold
			case 'f':
			case 'F':
				players.at(i).fold();
				break;
			// raise
			case 'r':
			case 'R':
				// display the highest amount a player has put in (the amount that needs to be raised to)
				cout << "Currently on table: " << current_table << endl;
				cout << "Minimum to raise: " << min_raise << endl;
				cout << "Available: " << players.at(i).getChips() << endl;
				// get amount to bet & bet
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

