#include "CarPart.h"
#include <iostream>
#pragma warning(disable: 4996)

unsigned CarPart::createdObjects = 1;

void CarPart::copyManufacturer(const CarPart& other) {
	this->manufacturerName = new char[strlen(other.manufacturerName) + 1];
	strcpy(this->manufacturerName, other.manufacturerName);
}

void CarPart::copyDescription(const CarPart& other) {
	this->description = new char[strlen(other.description) + 1];
	strcpy(this->description, other.description);
}

void CarPart::copyFrom(const CarPart& other) {
	copyManufacturer(other);
	copyDescription(other);
	id = other.id;
}

void CarPart::moveFrom(CarPart&& other) noexcept {
	id = other.id;
	manufacturerName = other.manufacturerName;
	description = other.description;

	other.description = nullptr;
	other.manufacturerName = nullptr;
	other.id = 0;
}

void CarPart::free() {
	delete[] manufacturerName;
	delete[] description;
	id = 0;
}

CarPart::CarPart(const char* manufacturer, const char* description) {
	id = createdObjects;
	createdObjects++;

	this->manufacturerName = new char[strlen(manufacturer) + 1];
	strcpy(this->manufacturerName, manufacturer);

	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

CarPart::CarPart(const CarPart& other) {
	copyFrom(other);
}

CarPart::CarPart(CarPart&& other) noexcept {
	moveFrom(std::move(other));
}

CarPart& CarPart::operator=(const CarPart& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

CarPart& CarPart::operator=(CarPart&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

CarPart::~CarPart() {
	free();
}

std::ostream& operator<<(std::ostream& os, const CarPart& obj) {
	os << obj.id << " by " << obj.manufacturerName << " - " << obj.description;

	return os;
}
