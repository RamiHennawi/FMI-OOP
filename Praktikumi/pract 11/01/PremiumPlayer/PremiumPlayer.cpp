#include "PremiumPlayer.h"

void PremiumPlayer::copyFrom(const PremiumPlayer& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void PremiumPlayer::moveFrom(PremiumPlayer&& other) noexcept {
	name = other.name;

	delete[] other.name;
}

void PremiumPlayer::free() {
	delete[] name;
}

PremiumPlayer::PremiumPlayer(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

PremiumPlayer::PremiumPlayer(const PremiumPlayer& other) : Player(other) {
	copyFrom(other);
}

PremiumPlayer::PremiumPlayer(PremiumPlayer&& other) noexcept : Player(std::move(other)) {
	moveFrom(std::move(other));
}

PremiumPlayer& PremiumPlayer::operator=(const PremiumPlayer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
		Player::operator=(other);
	}
	
	return *this;
}

PremiumPlayer& PremiumPlayer::operator=(PremiumPlayer&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
		Player::operator=(std::move(other));
	}

	return *this;
}

PremiumPlayer::~PremiumPlayer() {
	free();
}

bool PremiumPlayer::levelUp() {
	if (points >= 256 && stars == Stars::ONE) {
		stars == Stars::TWO;
		points = 0;
		return true;
	}
	else if (points >= 256 && stars == Stars::TWO) {
		stars == Stars::THREE;
		points = 0;
		return true;
	}
	else if (points >= 256 && stars == Stars::THREE) {
		stars == Stars::FOUR;
		points = 0;
		return true;
	}
	else if (points >= 256 && stars == Stars::FOUR) {
		stars == Stars::FIVE;
		points = 0;
		return true;
	}

	return false;
}
