#pragma once
#include "Player.h"

class Guest : public Player {
public:
	Guest() = default;
	Guest(unsigned playTime);

	bool levelUp() override;

private:
	unsigned playTime = 0;
};

