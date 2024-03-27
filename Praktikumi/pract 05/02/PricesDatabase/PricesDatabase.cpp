#include "PricesDatabase.h"

#include <iostream>

PricesDatabase::PricesDatabase() : size(0), prices() {};

State PricesDatabase::addPrice(size_t productId, double price) {
	if (size >= MAX_PRICES_SIZE) {
		return State::PriceFull;
	}
	if (price < 0) {
		return State::NegativePrice;
	}

	Price newPrice(productId, price);
	prices[size] = newPrice;
	size++;
}

double PricesDatabase::getPrice(size_t productId) const {
	for (int i = 0; i < size; i++) {
		if (prices[i].getId() == productId) {
			return prices[i].getPrice();
		}
	}

	return 0;
}