#include "ProductsDatabase.h"

#include <iostream>

ProductsDatabase::ProductsDatabase() : size(0), products() {};

bool ProductsDatabase::existsProduct(size_t id) const {
	for (int i = 0; i < size; i++) {
		if (products[i].getProductID() == id) {
			return true;
		}
	}

	return false;
}

State ProductsDatabase::addProduct(const char* name, size_t ownerID, size_t productID, size_t quantity) {
	if ((size + 1) > MAX_PRODUCTS_SIZE) {
		return State::ProductFull;
	}

	if (!existsProduct(productID)) {
		Product newProduct(ownerID, quantity, productID, name);
		products[size] = newProduct;
		size++;
	}
}

size_t ProductsDatabase::itemsOwned(size_t ownerID, size_t productID) const {
	for (int i = 0; i < size; i++) {
		if (products[i].getProductID() == productID && products[i].getOwnerID() == ownerID) {
			return products[i].getQuantity();
		}
	}

	return 0;
}

State ProductsDatabase::update(size_t ownerID, size_t productID, int update) {
	for (int i = 0; i < size; i++) {
		if (products[i].getProductID() == productID && products[i].getOwnerID() == ownerID) {
			return products[i].updateQuantity(update);
		}
	}
}

bool ProductsDatabase::existsUserWithProduct(size_t ownerID, size_t productID) {
	for (int i = 0; i < size; i++) {
		if (products[i].getProductID() == productID && products[i].getOwnerID() == ownerID) {
			return true;
		}
	}

	return false;
}

const char* ProductsDatabase::getProductName(size_t productID) const {
	for (int i = 0; i < size; i++) {
		if (products[i].getProductID() == productID) {
			return products[i].getName();
		}
	}

	return "";
}
