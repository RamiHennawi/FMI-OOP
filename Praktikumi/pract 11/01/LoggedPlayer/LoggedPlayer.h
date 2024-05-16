#pragma once
#include "Player.h"

constexpr size_t MAX_PASSWORD_SIZE = 8;

class LoggedPlayer : public Player {
public:
	LoggedPlayer(const char* password);

	bool levelUp() override;

	bool comparePassword(const char* inputPassword) const;

private:
	char password[MAX_PASSWORD_SIZE];
};

bool login(LoggedPlayer* playerDatabase, size_t playersCount, int id, const char* password);
