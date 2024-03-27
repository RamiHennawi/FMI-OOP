#include "Price.h";

#include <iostream>

Price::Price() : productId(0), price(0) {};

Price::Price(size_t productId, double price) : productId(productId) {
	if (price >= 0) {
		this->price = price;
	}
}

double Price::getPrice() const {
	return price;
}

size_t Price::getId() const {
	return productId;
}

State Price::updatePrice(double amount) {
	if ((price + amount) < 0) {
		return State::NegativePrice;
	}

	price += amount;
}