/**
* Author - Rory Magowan, James Neil, Daniel Brereton, Daniel Kinnaird, Shaun Falconer
* Version 1.0 3rd December 2015
*
*/
#include <iostream>
#include <algorithm>
#include "PokerSim.h"
#include "Genio.cpp"


using namespace std;

/**
* Method which checks if a given name is in the players vector
*
* param - name : name to be searched for in the vector
*/
bool PokerSim::isInPlayers(string name){
	
	for (int i = 0; i < players.size(); i++)
		{
			if(name == players.at(i).getName()){
				return true;
			}
		}

	return false;
}

/**
* Method to set up the game of poker, letting the user add each player and the desired number
* of starting chips
*
*/
void PokerSim::setPlayers(){

	int chips;
	int noOfPlayers;
	string name;
	bool validName;

	//Runs until user enters a value greater than 0
	while(true){

		cout << "Please enter number of Starting Chips : " << endl;
		chips = Genio::readInt();
		if(chips > 0){break;}

		cout << "Please enter a value greater than 0" << endl;

	}

	//Runs until user enters a value between 2 and 10
	while(true){

		cout << "Please enter number of Players: " << endl;
		noOfPlayers = Genio::readInt();
		if(noOfPlayers > 1 && noOfPlayers <= 10){break;}

		cout << "Please enter a value between 2 and 10" << endl;

	}

	//Asks for each players name, but only accepts unique names
	for(int i = 0; i < noOfPlayers; i++){

		do{

			validName = true;
			cout << "Enter Player " << i+1 << "'s Name: " << endl;
			getline(cin, name);
			name = Genio::strToLower(name);

		}while(isInPlayers(name));
		Player temp(name, chips);
		players.push_back(temp);
	}
	cout << endl;

}

/**
* Method to unfold all the players at the beginning of a hand
*
*/
void PokerSim::unFoldPlayers(){

	for(int i = 0; i < players.size(); i++){

		players.at(i).setFold(false);

	}

}

/**
* Method to display relevant information to the player about their chips, bets and what descision
* they have to make
*
* param - i : index for the players vector
*/
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

/**
* Method to count how many players aren't folded in the current hand
*
* return - count : the number of players who aren't folded
*/
int PokerSim::countPlayersHand(){

	int count = 0;

	for(int i = 0; i < players.size(); i++){

		if(!players.at(i).isFolded()){count++;}

	}

	return count;

}

/**
* Method to check (call a bet of 0 chips) or call the current bet
*
* return : if all the players have called the current bet (indication to move on)
*/
bool PokerSim::checkCall(int i){

	//The number of chips the player need to put in to call the bet
	int to_call = highest_bet - players.at(i).getCurrentBet();

	//Checks if the player has enough chips to call
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

	//Checks if every player has put in the same amount
	for(int j = 0; j < players.size(); j++){

		if(players.at(j).isFolded() == false && players.at(j).getCurrentBet() != highest_bet){

			return false;

		}

	}

	return true;

}

/**
* Method to let the player raise the current bet
*
* param - i : index for the player vector
*/
void PokerSim::raise(int i){

	//Checks if the player has enough chips to raise (In poker players can only raise at least
	//double the previous bet)
	if(players.at(i).getChips() < highest_bet*2){

		//Puts player all in if they don't have enough to raise to the min raise
		pot += players.at(i).getChips();
		players.at(i).bet(players.at(i).getChips());
		cout << "You're all in!" << endl;
		return;

	}

	// get amount to bet from the user & bets it
	int to_bet;
	do{

		cout << "Enter amount to raise: " << endl;
		to_bet = Genio::readInt();

	}while(to_bet < highest_bet*2 || to_bet > players.at(i).getChips());	

	players.at(i).bet(to_bet);
	pot += to_bet;
	highest_bet = to_bet;

}

/**
* Method to simulate the flow of a single beting stage of a poker hand (pre-flop, flop etc.)
* until either all but one players has folded, or every player has been seen to and have all
* matched the highest bet
*
*/
void PokerSim::betting(){
	
	//whether of not all the players have matched the highest bet
	bool allCalled = false;
	int i = -1;
	//counts how many players have been seen to since the last bet
	int backAround = 0;

	while(!(allCalled == true && backAround == players.size())){
		
		//increments i but loops back round to the first player after it reaches the last player
		i = (i+1) % players.size();
		if(backAround < players.size()){
			backAround++;
		}

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
			// check/call
			case 'c':
			case 'C':
			    allCalled = checkCall(i);
				break;
			// fold
			case 'f':
			case 'F':
				players.at(i).setFold(true);
				if(countPlayersHand() == 1){
					
					//Skips the rest of the betting if only 1 player remains
					goto exitLoop;

				}
				break;
			// raise
			case 'r':
			case 'R':
			    raise(i);
				//resets the backAround counter and the allCalled variable
			    backAround = 1;
			    allCalled = false;
				break;
			default:
				cout << "ERROR: Invalid selection." << endl;
				break;
		}
	}
	//exit point for if only 1 player remains
	exitLoop: ;
}

/**
* Method to let the user input who won the hand and give them the chips
*
*/
void PokerSim::winner(){

	string winner;
	
	//Ask user for the player's name until they enter a name in the players vector
	do{
		cout << "Who won the round: " << endl;
		getline(cin >> ws, winner);
		winner = Genio::strToLower(winner);
	}
	while(!isInPlayers(winner));

	for(int i = 0; i < players.size(); i++){

		if(players.at(i).getName() == winner){

			//Gives the player the chips from the pot and resets the pot to 0
			players.at(i).win(pot);
			pot = 0;
			break;

		}

	}
	
}

/**
* Method to reset all the players current bets to 0
*
*/
void PokerSim::resetBets(){

	highest_bet = 0;
	for(int i = 0; i < players.size(); i++){

		players.at(i).setCurrentBet(0);

	}

}

/**
* Method to remove a player from the players vector (and therefore from the game) if they have
* run out of chips
*
*/
void PokerSim::out(){

	for(int i = 0; i < players.size(); i++){

		if(players.at(i).getChips() == 0){

			players.erase(players.begin()+i);

		}

	}	

}

/**
* Method to simulate the betting for all the stages of a single hand
*
*/
void PokerSim::hand(){

	unFoldPlayers();

	//Pre-Flop (No cards on table)
	cout << "PRE-FLOP" << endl;
	resetBets();
	betting();
	cout << endl;

	//Flop (3 cards on table)
	cout << "FLOP" << endl;
	resetBets();
	betting();
	cout << endl;

	//Turn (4 cards on table)
	cout << "TURN" << endl;
	resetBets();
	betting();
	cout << endl;

	//River (5 cards on table)
	cout << "RIVER" << endl;
	resetBets();
	betting();
	cout << endl;

	//Select winner for the hand
	winner();
	//Remove anyone with 0 chips from the game
	out();


}

/**
* Method to simulate the game from hand to hand until only 1 player has all of the chips
*
*/
void PokerSim::game(){

	//Resets the higest_bet and the pot for each hand
	this->highest_bet = 0;
	this->pot = 0;
	//Game setup
	setPlayers();
	//Keeps playing hands until only 1 players remains
	while(players.size() > 1){

		hand();

	}

	//Game end prompt
	cout << endl;
	cout << "Game Over!" << endl;
	cout << players.at(0).getName() << " wins the game!" << endl;
	cout << endl;



}

/**
* Constructor method for the PokerSim class which runs the game
*
*/
PokerSim::PokerSim() {

	game();

}

