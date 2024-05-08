#include "FuelTank.h"

insufficient_fuel_error::insufficient_fuel_error(const char* message) : std::logic_error(message) {}

FuelTank::FuelTank(double capacity) : CarPart("", "") {
	this->capacity = capacity;
	this->currentFullness = capacity;
}

FuelTank::FuelTank(const char* manufacturer, const char* description, double capacity) : CarPart(manufacturer, description) {
	this->capacity = capacity;
	this->currentFullness = capacity;
}

void FuelTank::use(double toUse) {
	if (currentFullness < toUse) {
		throw insufficient_fuel_error("Not enough fuel in tank.");
	}

	currentFullness -= toUse;
}

void FuelTank::fill(double toFill) {
	if ((currentFullness + toFill) >= capacity) {
		currentFullness = capacity;
	}
	else {
		currentFullness += toFill;
	}
}

double FuelTank::getCurrentFullness() const {
	return currentFullness;
}
