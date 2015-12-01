#include <string>

class Player {
private:
	string name;
	int chips;
public:
	Player(string name) {
		this->name = name;
		this->chips = 2000;
	}

	Player(string name, int chips) {
		this->name = name;
		this->chips = chips;
	}

	// bets <amount> number of chips
	// if player doesn't have enough chips return false
	// otherwise deduct chips from the player, and return true
	bool bet(int amount) {
		if(amount>chips) {
			return false;
		} 
		chips-=amount;
		return true;
	}

	int getChips() {
		return this->chips;
	}
}