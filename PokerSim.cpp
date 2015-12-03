#include <iostream>
#include "PokerSim.h"
#include "Genio.cpp"


using namespace std;

bool PokerSim::isInPlayers(string name){
	
	for (int i = 0; i < players.size(); i++)
		{
			if(name == players.at(i)){
				return true;
			}
		}

	return false;
}

void PokerSim::setPlayers(){

	int chips;
	int noOfPlayers;
	string name;
	bool validName;

	while(true){

		cout << "Please enter number of Starting Chips : " << endl;
		chips = Genio::readInt();
		if(chips > 0){break;}

		cout << "Please enter a value greater than 0" << endl;

	}

	while(true){

		cout << "Please enter number of Players: " << endl;
		noOfPlayers = Genio::readInt();
		if(noOfPlayers > 1 && noOfPlayers <= 10){break;}

		cout << "Please enter a value between 2 and 10" << endl;

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
	cout << endl;

}

void PokerSim::displayInfo(int i){

		cout << endl;
		cout << "Bet to call: " << highest_bet << endl;
		cout << "Minimum to raise: " << highest_bet*2 << endl;
		cout << "Your chips: " << players.at(i).getChips() << endl;
		cout << "Chips in pot: " << pot << endl;
		cout << endl;
		// prompt for selection
		cout << "[" << players.at(i).getName() << "] Make selection.." << endl;
		//Gives the player the option to check if there is no bet or call is there is one
		highest_bet == 0 ? cout << "[C]heck" << endl : cout << "[C]all" << endl;
		cout << "[F]old" << endl;
		cout << "[R]aise" << endl;

}

int PokerSim::countPlayersGame(){

	int count = 0;

	for(int i = 0; i < players.size(); i++){

		if(players.at(i).getChips() > 0){count++;}

	}

	return count;

}

int PokerSim::countPlayersHand(){

	int count = 0;

	for(int i = 0; i < players.size(); i++){

		if(!players.at(i).isFolded()){count++;}

	}

	return count;

}

bool PokerSim::checkCall(int i){

	int to_call = highest_bet - players.at(i).getCurrentBet();

	if(players.at(i).getChips() <= highest_bet){

		pot += players.at(i).getChips();
		//Puts player all in if they do not have enough chips to call
		players.at(i).bet(players.at(i).getChips());
		cout << "You're all in!" << endl;

	}
	else{

		//Calls the bet or checks if highest bet is 0
		players.at(i).bet(to_call);
		pot += to_call;

	}

	for(int j = 0; j < players.size(); j++){

		if(players.at(j).isFolded() == false && players.at(j).getCurrentBet() != highest_bet){

			return false;

		}

	}

	return true;

}

void PokerSim::raise(int i){

	if(players.at(i).getChips() < highest_bet*2){

		//Puts player all in if they don't have enough to raise to the min raise
		pot += players.at(i).getChips();
		players.at(i).bet(players.at(i).getChips());
		cout << "You're all in!" << endl;
		return;

	}

	// get amount to bet & bet
	int to_bet;
	do{

		cout << "Enter amount to raise: " << endl;
		to_bet = Genio::readInt();

	}while(to_bet < highest_bet*2 || to_bet > players.at(i).getChips());	

	players.at(i).bet(to_bet);
	pot += to_bet;
	highest_bet = to_bet;

}

void PokerSim::hand() {
	
	bool allCalled = false;
	int i = -1;
	int backAround = 0;

	// for each player in vector <players>
	while(!(allCalled == true && backAround == players.size())){
		
		i = (i+1) % players.size();
		int available = players.at(i).getChips();
		backAround++;

		// if the player is folded
		if(players.at(i).isFolded()) {
			// skip to next iteration
			continue;
		}

		displayInfo(i);
		// get selection
		char selection;
		cin >> selection;
		switch(selection) {
			// check
			case 'c':
			case 'C':
			    allCalled = checkCall(i);
				break;
			// fold
			case 'f':
			case 'F':
				players.at(i).fold();
				if(countPlayersHand() == 1){goto exitLoop;}
				break;
			// raise
			case 'r':
			case 'R':
			    raise(i);
			    backAround = 1;
			    allCalled = false;
				break;
			default:
				cout << "ERROR: Invalid selection." << endl;
				break;
		}
	}
	exitLoop: ;
}

void PokerSim::winner(){

	string winner;
	
	do{
	cout << "Who won the round: " << endl;
	getline(cin, winner);
	}
	while(!isInPlayers(winner));	
	
}

void PokerSim::round(){

	cout << "PRE-FLOP" << endl;
	hand();
	cout << endl;

	cout << "FLOP" << endl;
	hand();
	cout << endl;

	cout << "TURN" << endl;
	hand();
	cout << endl;

	cout << "RIVER" << endl;
	hand();
	cout << endl;


}

void PokerSim::game(){

	this->highest_bet = 0;
	this->pot = 0;
	setPlayers();
	while(countPlayersGame() > 1){

		round();

	}

}

PokerSim::PokerSim() {

	game();

}

