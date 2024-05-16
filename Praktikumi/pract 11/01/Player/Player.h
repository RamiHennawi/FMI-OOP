#pragma once
#include <iostream>

enum class Stars : uint8_t {
	ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
};

class Player {
public:
	Player();
	virtual ~Player() = default;

	virtual bool levelUp() = 0;

	int getID() const;

protected:
	int id = 0;
	unsigned points = 0;
	Stars stars = Stars::ONE;

private:
	static int createdPlayers;
};
