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

