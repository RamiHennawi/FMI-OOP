#pragma once
#include "CarPart.h"

namespace TireConstants {
	constexpr unsigned MIN_WIDTH = 155;
	constexpr unsigned MAX_WIDTH = 365;

	constexpr unsigned MIN_PROFILE = 30;
	constexpr unsigned MAX_PROFILE = 80;

	constexpr unsigned MIN_DIAMETER = 13;
	constexpr unsigned MAX_DIAMETER = 21;
}

class Tire : public CarPart {
public:
	Tire(unsigned width, unsigned profile, unsigned diameter);
	Tire(const char* manufacturer, const char* description, unsigned width, unsigned profile, unsigned diameter);

	friend std::ostream& operator<<(std::ostream& os, const Tire& obj);

private:
	unsigned width = TireConstants::MIN_WIDTH; // in mm
	unsigned profile = TireConstants::MIN_PROFILE;
	unsigned diameter = TireConstants::MIN_DIAMETER; // in inches
};
