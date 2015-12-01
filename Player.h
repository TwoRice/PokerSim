using namespace std;

class Player {
private:
	string name;
	int chips;
	int current_bet;
	bool folded;
public:
	Player(string name);
	Player(string name, int chips);
	
	bool bet(int amount);
	void win(int winnings);

	string getName();
	int getChips();
	int getCurrentBet();
	bool isFolded();

	void setCurrentBet(int bet);
	void appendName(string end);

	void fold();
};
