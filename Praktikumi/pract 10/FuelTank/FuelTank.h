#pragma once
#include "CarPart.h"
#include <stdexcept>

class insufficient_fuel_error : public std::logic_error {
public:
	explicit insufficient_fuel_error(const char* message);
};

class FuelTank : public CarPart  {
public:
	FuelTank(double capacity);
	FuelTank(const char* manufacturer, const char* description, double capacity);

	void use(double toUse);
	void fill(double toFill);

	double getCurrentFullness() const;

private:
	double capacity; // in liters
	double currentFullness; // in liters
};

