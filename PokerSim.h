#include <vector>

class PokerSim{
	private:
		int pot;
		vector<Player> players;
	public: 
		PokerSim();
		void setPlayers();
		void begin();
};