#include "LoggedPlayer.h"

LoggedPlayer::LoggedPlayer(const char* password) {
	if (strlen(password) > MAX_PASSWORD_SIZE) {
		throw std::length_error("Password exceeds limit");
	}

	strcpy(this->password, password);
}

bool LoggedPlayer::levelUp() {
	if (points >= 256 && stars == Stars::ONE) {
		stars == Stars::TWO;
		points = 0;
		return true;
	}
	else if (points >= 512 && stars == Stars::TWO) {
		stars == Stars::THREE;
		points = 0;
		return true;
	}
	else if (points >= 1024 && stars == Stars::THREE) {
		stars == Stars::FOUR;
		points = 0;
		return true;
	}
	else if (points >= 2048 && stars == Stars::FOUR) {
		stars == Stars::FIVE;
		points = 0;
		return true;
	}

	return false;
}

bool LoggedPlayer::comparePassword(const char* inputPassword) const {
	return strcmp(password, inputPassword) == 0;
}

bool login(const LoggedPlayer* players, size_t playersCount, int id, const char* password) {
	for (size_t i = 0; i < playersCount; i++) {
		if ((players[i].getID() == id) && players[i].comparePassword(password)) {
			return true;
		}
	}

	return false;
}