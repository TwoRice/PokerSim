#include <vector>
#include "Player.cpp"

class PokerSim {
	private:
		int pot;
		int highest_bet;

		vector<Player> players;
	public: 
		PokerSim();
		bool isInPlayers(string name):
		void setPlayers();
		void displayInfo(int i);
		int countPlayersGame();
		int countPlayersHand();
		bool checkCall(int i);
		void raise(int i);
		void hand();
		void winner();
		void round();
		void game();
};
