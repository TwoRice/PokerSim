#include <vector>

class PokerSim {
	private:
		int pot;
		int current_max;
		
		vector<Player> players;
	public: 
		PokerSim();
		void setPlayers();
		void begin();
};