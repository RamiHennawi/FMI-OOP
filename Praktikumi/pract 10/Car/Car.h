#pragma once
#include "Battery.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Tire.h"

constexpr size_t TIRES_PER_CAR = 4;
constexpr double FUEL_USED_PER_KM = 1;
constexpr double DISTANCE_IN_DRAG_RACE = 0.4; // in km

constexpr double EPSILON = 0.0001;

class Car {
public:
	Car(unsigned kilometersPassed, unsigned weight, Engine* enginePtr, Tire* tiresPtr[TIRES_PER_CAR], Battery* batteryPtr, const FuelTank& fuelTank);

	const FuelTank& getFuelTank() const;
	unsigned getHorsePowerOfEngine() const;
	unsigned getWeight() const;

	void drive(double km);

private:
	unsigned kilometersPassed;
	unsigned weight; // in kg
	Engine* engine;
	Tire* tires[TIRES_PER_CAR];
	Battery* battery;
	FuelTank fuelTank;
};

Car* dragRace(Car* car1, Car* car2);

