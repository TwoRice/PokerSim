class Player {
private:
	string name;
	int chips;
public:
	Player(string name);
	Player(string name, int chips);

	bool bet(int amount);
	string getName();
	int getAmount();
	void appendName(string end);
}