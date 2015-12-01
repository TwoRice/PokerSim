#include <string>
#include "Player.h"

Player::Player(string name) {
	this->name = name;
	this->chips = 2000;
	this->folded = false;
}

Player::Player(string name, int chips) {
	this->name = name;
	this->chips = chips;
	this->folded = false;
}

// bets <amount> number of chips
// if player doesn't have enough chips return false
// otherwise deduct chips from the player, and return true
bool Player::bet(int amount) {
	if(amount>chips) {
		return false;
	} 
	this->chips-=amount;
	return true;
}

void Player::win(int winnings) {
	this->chips+=winnings;
}

string Player::getName() {
	return this->name;
}

int Player::getChips() {
	return this->chips;
}

void Player::getCurrentBet() {
	return this->current_bet;
}

bool Player::isFolded() {
	return folded;
}

void Player::setCurrentBet(int bet) {
	this->current_bet = bet;
}

bool Player::fold() {
	this->folded = true;
}

void Player::appendName(string end) {
	this->name+=end;
}