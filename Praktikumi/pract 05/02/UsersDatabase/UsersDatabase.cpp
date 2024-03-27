#include "UsersDatabase.h";

#include <iostream>

UsersDatabase::UsersDatabase() : size(0), users() {};

bool UsersDatabase::existsUser(size_t id) const {
	for (int i = 0; i < size; i++) {
		if (users[i].getID() == id) {
			return true;
		}
	}

	return false;
}

State UsersDatabase::addUser(size_t id, double balance, const char* name) {
	if ((size + 1) > MAX_USERS_SIZE) {
		return State::UserFull;
	}

	if (!existsUser(id)) {
		User newUser(id, balance, name);

		users[size] = newUser;
		size++;
	}
}

bool UsersDatabase::hasEnoughMoney(size_t id, double money) const {
	for (int i = 0; i < size; i++) {
		if (users[i].getID() == id) {
			return users[i].hasMoney(money);
		}
	}
}

void UsersDatabase::updateMoney(size_t id, double money) {
	for (int i = 0; i < size; i++) {
		if (users[i].getID() == id) {
			users[i].updateMoney(money);
		}
	}
}
