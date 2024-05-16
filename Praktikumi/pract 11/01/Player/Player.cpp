#include "Player.h"

int Player::createdPlayers = 1;

Player::Player() {
	id = createdPlayers;
	createdPlayers++;
}

int Player::getID() const {
	return id;
}