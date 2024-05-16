#pragma once
#include "Prize.h"

class ComputerBoy : public Prize {
public:
	ComputerBoy();
	void visualize() override;
};
