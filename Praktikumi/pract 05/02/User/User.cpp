#include "User.h"
#include <iostream>
#pragma warning(disable: 4996);

User::User() : id(0), balance(0) {
	strcpy(name, "");
}

User::User(size_t id, double balance, const char* name) {
	this->id = id;

	if (balance > 0) {
		this->balance = balance;
	}

	if (strlen(name) <= MAX_NAME_SIZE) {
		strcpy(this->name, name);
	}
}

State User::updateMoney(double factor) {
	if ((balance + factor) < 0) {
		return State::NegativeBalance;
	}

	balance += factor;
}

bool User::hasMoney(double arg) const {
	return balance >= arg;
}

size_t User::getID() const {
	return id;
}