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

