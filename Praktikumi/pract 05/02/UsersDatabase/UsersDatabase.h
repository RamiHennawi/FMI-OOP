#pragma once
#include "State.h";
#include "User.h";

constexpr size_t MAX_USERS_SIZE = 50;

class UsersDatabase {
	size_t size = 0;
	User users[MAX_USERS_SIZE] = {};

public:
	UsersDatabase();

	State addUser(size_t id, double balance, const char* name);
	bool hasEnoughMoney(size_t id, double money) const;
	bool existsUser(size_t id) const;
	void updateMoney(size_t id, double money);
};
