#pragma once
#include "Prize.h"

class Pacman : public Prize {
public:
	Pacman();
	void visualize() override;
};
