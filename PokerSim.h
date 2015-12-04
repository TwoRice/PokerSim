/**
* Class which simulates the betting flow of poker using a vector of players and methods for
* betting, calling, raising ,folding etc.
*
* Author - Rory Magowan, James Neil, Daniel Brereton, Daniel Kinnaird, Shaun Falconer
* Version 1.0 3rd December 2015
*/
#include <vector>
#include "Player.cpp"

class PokerSim {
	private:
		int pot;
		int highest_bet;

		vector<Player> players;
	public: 
		PokerSim();
		bool isInPlayers(string name);
		void setPlayers();
		void unFoldPlayers();
		void displayInfo(int i);
		int countPlayersHand();
		bool checkCall(int i);
		void raise(int i);
		void betting();
		void winner();
		void resetBets();
		void out();
		void hand();
		void game();
};
