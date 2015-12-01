using namespace std;

class Player {
private:
	string name;
	int chips;
public:
	Player(string name);
	Player(string name, int chips);

	bool bet(int amount);
	void win(int winnings);
	string getName();
	int getAmount();
	void appendName(string end);
};
