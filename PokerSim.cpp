#include "PokerSim.h";

void setPlayers(){

int chips;
int num;
string name;

cout << "Please enter number of Starting Chips" << endl;
cin >> chips >> endl;
cout << "Starting Chips set to: " << chips << endl;

cout << "Please enter number of Players: " << endl;
cin >> num >> endl;

	for(int i = 0; i < num; i++){

		cout << "Enter Player" << i << "'s Name: " << endl;
		cin >> name >> endl;
		Player  = new Player(name, chips);

	}

}

