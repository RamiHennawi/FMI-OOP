#include "Battery.h"
#include <iostream>
#pragma warning(disable: 4996)

void Battery::copyFrom(const Battery& other) {
	capacity = other.capacity;

	id = new char[strlen(other.id) + 1];
	strcpy(id, other.id);
}

void Battery::moveFrom(Battery&& other) noexcept {
	capacity = other.capacity;
	id = other.id;

	other.capacity = 0;
	other.id = nullptr;
}

void Battery::free() {
	delete[] id;
	capacity = 0;
}

Battery::Battery(unsigned capacity, const char* id) : CarPart("", "") {
	this->capacity = capacity;

	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);
}

Battery::Battery(const char* manufacturer, const char* description, unsigned capacity, const char* id) : CarPart(manufacturer, description) {
	this->capacity = capacity;

	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);
}

Battery::Battery(const Battery& other) : CarPart(other) {
	copyFrom(other);
}

Battery::Battery(Battery&& other) noexcept : CarPart(std::move(other)) {
	moveFrom(std::move(other));
}

Battery& Battery::operator=(const Battery& other) {
	if (this != &other) {
		CarPart::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

Battery& Battery::operator=(Battery&& other) noexcept {
	if (this != &other) {
		CarPart::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Battery::~Battery() {
	free();
}

std::ostream& operator<<(std::ostream& os, const Battery& obj) {
	operator<<(os, (CarPart&)obj);
	os << " - " << obj.capacity << " Ah" << std::endl;

	return os;
}
