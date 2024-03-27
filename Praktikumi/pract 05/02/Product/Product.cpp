#include "Product.h";

#include <iostream>

Product::Product() {
	ownerId = 0;
	quantity = 0;
	productId = 0;
	strcpy(name, "");
}

Product::Product(size_t ownerId, size_t quantity, size_t productId, const char* name) : ownerId(ownerId), productId(productId) {
	if (quantity >= 0) {
		this->quantity = quantity;
	}

	if (strlen(name) <= MAX_NAME_SIZE) {
		strcpy(this->name, name);
	}
}

State Product::updateQuantity(int amount) {
	if ((quantity + amount) < 0) {
		return State::NegativeQuantity;
	}

	quantity += amount;
}

size_t Product::getQuantity() const {
	return quantity;
}

size_t Product::getProductID() const {
	return productId;
}

size_t Product::getOwnerID() const {
	return ownerId;
}

const char* Product::getName() const {
	return name;
}