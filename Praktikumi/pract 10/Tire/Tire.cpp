#include "Tire.h"
#include <stdexcept>

Tire::Tire(unsigned width, unsigned profile, unsigned diameter) : CarPart("", "") {
	if ((width < TireConstants::MIN_WIDTH || width > TireConstants::MAX_WIDTH) ||
		(profile < TireConstants::MIN_PROFILE || profile > TireConstants::MAX_PROFILE) ||
		(diameter < TireConstants::MIN_DIAMETER || diameter > TireConstants::MAX_DIAMETER)) {
		throw std::invalid_argument("Invalid tire parameter.");
	}

	this->width = width;
	this->profile = profile;
	this->diameter = diameter;
}

Tire::Tire(const char* manufacturer, const char* description, unsigned width, unsigned profile, unsigned diameter)
	: CarPart(manufacturer, description) {
	this->width = width;
	this->profile = profile;
	this->diameter = diameter;
}

std::ostream& operator<<(std::ostream& os, const Tire& obj) {
	operator<<(os, (CarPart&)obj);
	os << " - " << obj.width << "/" << obj.profile << "R" << obj.diameter << std::endl;

	return os;
}
