/**
* Author - Rory Magowan, James Neil, Daniel Brereton, Daniel Kinnaird, Shaun Falconer
* Version 1.0 3rd December 2015
*
*/
#include <string>
#include "Player.h"

/**
* Constructor for a player which sets a default number of chips of 2000
*
* param - name : The unique name of the player
*/
Player::Player(string name) {
	this->name = name;
	this->chips = 2000;
	this->folded = false;
	this->current_bet = 0;
}

/**
* Constructor for a player with a user given value for their chips
*
* param - name : The unique name of the player
* param - chips : The number of chips the player starts with
*/
Player::Player(string name, int chips) {
	this->name = name;
	this->chips = chips;
	this->folded = false;
	this->current_bet = 0;
}

// bets <amount> number of chips
// if player doesn't have enough chips return false
// otherwise deduct chips from the player, and return true
bool Player::bet(int amount) {
	if(amount>chips) {
		return false;
	} 
	this->chips-=amount;
	this->current_bet += amount;
	return true;
}

/**
* Method to give the player their winnings from the pot
*
* param - winnings : The number of chips being given to the player
*/
void Player::win(int winnings) {
	this->chips+=winnings;
}

/**
* Getter method for the players name
*
* return - name : The unique name for the player
*/
string Player::getName() {
	return this->name;
}

/**
* Getter method for the players chips
*
* return - chips : the number of chips the player has
*/
int Player::getChips() {
	return this->chips;
}

/**
* Getter method for the player's current bet
*
* return - current_bet : the number of chips the player has bet
*/
int Player::getCurrentBet() {
	return this->current_bet;
}

/**
* Getter method for whether or not the player has folded 
*
* return - folded : whether or not the player has folded
*/
bool Player::isFolded() {
	return folded;
}

/**
* Setter method for the player's current bet
*
* param - bet : the numbers of chips the player has bet
*/
void Player::setCurrentBet(int bet) {
	this->current_bet = bet;
}

/**
* Setter method for whether or not the player has folded
*
* param - folded : whether or not the player has folded
*/
void Player::setFold(bool folded) {
	this->folded = folded;
}
