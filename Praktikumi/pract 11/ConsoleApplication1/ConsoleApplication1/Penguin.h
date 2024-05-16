#pragma once
#include "Prize.h"

class Penguin : public Prize {
public:
	Penguin();
	void visualize() override;
};
