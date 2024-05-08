#include "Engine.h"

Engine::Engine(unsigned horsePower) : CarPart("", "") {
	this->horsePower = horsePower;
}

Engine::Engine(const char* manufacturer, const char* description, unsigned horsePower) : CarPart(manufacturer, description) {
	this->horsePower = horsePower;
}

unsigned Engine::getHorsePower() const {
	return horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& obj) {
	operator<<(os, (CarPart&)obj);
	os << " - " << obj.horsePower << " hp" << std::endl;

	return os;
}
