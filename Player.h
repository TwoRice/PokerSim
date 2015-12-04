/**
* Class which holds the data and methods for a single player in the game
*
* Author - Rory Magowan, James Neil, Daniel Brereton, Daniel Kinnaird, Shaun Falconer
* Version 1.0 3rd December 2015
*/
using namespace std;

class Player {
private:
	string name;
	int chips;
	int current_bet;
	//Variable which holds whether of not the player has folded the hand
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

	void setFold(bool folded);
};
