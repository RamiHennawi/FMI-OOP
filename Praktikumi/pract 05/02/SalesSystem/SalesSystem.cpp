#include "SalesSystem.h"

#include <iostream>

SalesSystem::SalesSystem() : users(), products(), prices() {};

void SalesSystem::addUser(size_t id, double balance, const char* name) {
	users.addUser(id, balance, name);
}

State SalesSystem::addProduct(const char* name, size_t ownerID, size_t productID, size_t quantity) {
	if (!users.existsUser(ownerID)) {
		return State::UserNotFound;
	}

	return products.addProduct(name, ownerID, productID, quantity);
}

State SalesSystem::addPrice(size_t productId, double price) {
	if (!products.existsProduct(productId)) {
		return State::ProductNotFound;
	}

	return prices.addPrice(productId, price);
}

State SalesSystem::sell(size_t idFrom, size_t idTo, size_t productID, size_t quantity) {
	if (!users.existsUser(idFrom) || !users.existsUser(idTo)) {
		return State::UserNotFound;
	}

	if (products.existsProduct(productID)) {
		return State::ProductNotFound;
	}

	if (!users.hasEnoughMoney(idTo, quantity * prices.getPrice(productID))) {
		return State::ShortOnMoney;
	}

	if (!products.itemsOwned(idFrom, productID)) {
		return State::NotEnoughItems;
	}

	products.update(idFrom, productID, -quantity);
	
	if (!products.existsUserWithProduct(idTo, productID)) {
		products.addProduct(products.getProductName(productID), idTo, productID, quantity);
	}
	else {
		products.update(idTo, productID, quantity);
	}
	
	double totalMoney = quantity * prices.getPrice(productID);
	users.updateMoney(idFrom, totalMoney);
	users.updateMoney(idTo, -totalMoney);
}
