#include <vector>

class PokerSim {
	private:
		int pot;
		int current_table;

		vector<Player> players;
	public: 
		PokerSim();
		void setPlayers();
		void begin();
};