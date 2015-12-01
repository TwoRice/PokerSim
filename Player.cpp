#include <string>
#include "Player.h"

Player::Player(string name) {
	this->name = name;
	this->chips = 2000;
}

Player::Player(string name, int chips) {
	this->name = name;
	this->chips = chips;
}

// bets <amount> number of chips
// if player doesn't have enough chips return false
// otherwise deduct chips from the player, and return true
bool Player::bet(int amount) {
	if(amount>chips) {
		return false;
	} 
	chips-=amount;
	return true;
}

string Player::getName() {
	return this->name;
}

int Player::getAmount() {
	return this->chips;
}

void Player::appendName(string end) {
	this->name+=end;
}