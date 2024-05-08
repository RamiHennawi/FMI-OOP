#include "Car.h"

Car::Car(unsigned kilometersPassed, unsigned weight, Engine* enginePtr, Tire* tiresPtr[TIRES_PER_CAR], Battery* batteryPtr, const FuelTank& fuelTank)
	: kilometersPassed(kilometersPassed), weight(weight), engine(enginePtr), battery(batteryPtr), fuelTank(fuelTank) {
	for (int i = 0; i < TIRES_PER_CAR; ++i) {
		tires[i] = tiresPtr[i];
	}
}

const FuelTank& Car::getFuelTank() const {
	return fuelTank;
}

unsigned Car::getHorsePowerOfEngine() const {
	return engine->getHorsePower();
}

unsigned Car::getWeight() const {
	return weight;
}

void Car::drive(double km) {
	if (km < 0) {
		throw std::logic_error("Can't drive negative km");
	}
    else if ((fuelTank.getCurrentFullness() - km * FUEL_USED_PER_KM) < EPSILON) {
		return;
	}

	kilometersPassed += km;
	fuelTank.use(km * FUEL_USED_PER_KM);
}

Car* dragRace(Car* car1, Car* car2) {
	bool hasEnoughFuelCar1 = (car1->getFuelTank().getCurrentFullness() - DISTANCE_IN_DRAG_RACE * FUEL_USED_PER_KM) < EPSILON;
	bool hasEnoughFuelCar2 = (car2->getFuelTank().getCurrentFullness() - DISTANCE_IN_DRAG_RACE * FUEL_USED_PER_KM) < EPSILON;

	if (!car1 && !car2) {
		return nullptr;
	}
	else if (!car1 && car2) {
		return car2;
	}
	else if (car1 && !car2) {
		return car1;
	}

	double ratioCar1 = car1->getWeight() / car1->getHorsePowerOfEngine();
	double ratioCar2 = car2->getWeight() / car2->getHorsePowerOfEngine();
	return (ratioCar1 - ratioCar2) < EPSILON ? car2 : car1;
}