#pragma once
#include "State.h";

constexpr size_t MAX_NAME_SIZE = 32;

class User {
	size_t id = 0;
	double balance = 0;
	char name[MAX_NAME_SIZE + 1] = "";

public:
	User();

	User(size_t id, double balance, const char* name);

	State updateMoney(double factor);
	bool hasMoney(double arg) const;
	size_t getID() const;
};
