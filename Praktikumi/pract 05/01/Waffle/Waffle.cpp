#include "Waffle.h"

#include <iostream>
#pragma warning(disable: 4996);

Waffle::Waffle() {
	priceClient = 0;
	priceWholesale = 0;
	grammage = 0;
	strcpy(brand, "Unknown");
}

Waffle::Waffle(double priceClient, double priceWholesale, double gramage, const char* brand) {
	if (priceClient < 0 || priceWholesale < 0 || grammage < 0) {
		return;
	}

	this->priceClient = priceClient;
	this->priceWholesale = priceWholesale;
	this->grammage = grammage;
	strcpy(this->brand, brand);
}

double Waffle::getPriceClient() const {
	return priceClient;
}

double Waffle::getPriceWholesale() const {
	return priceWholesale;
}

double Waffle::getGrammage() const {
	return grammage;
}

const char* Waffle::getBrand() const {
	return brand;
}

void Waffle::setPriceClient(double price) {
	if (price < 0) {
		return;
	}

	this->priceClient = price;
}

void Waffle::setPriceWholesale(double price) {
	if (price < 0) {
		return;
	}

	this->priceWholesale = price;
}

void Waffle::setGrammage(double grammage) {
	if (grammage < 0) {
		return;
	}

	this->grammage = grammage;
}

void Waffle::setBrand(const char* brand) {
	strcpy(this->brand, brand);
}

void Waffle::print() {
	std::cout << "Brand: " << brand << ", Price wholesale: " << priceWholesale << ", Price for client: " << priceClient << ", Grammage: " << grammage << std::endl;
}
