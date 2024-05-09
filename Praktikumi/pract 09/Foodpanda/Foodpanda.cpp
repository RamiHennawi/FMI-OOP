#include "Foodpanda.h"

void Foodpanda::copyFrom(const Foodpanda& other) {
	restaurantsCount = other.restaurantsCount;
	capacity = other.capacity;

	restaurants = new Restaurant[capacity];
	for (size_t i = 0; i < restaurantsCount; i++) {
		restaurants[i] = other.restaurants[i];
	}
}

void Foodpanda::moveFrom(Foodpanda&& other) noexcept {
	restaurants = other.restaurants;
	restaurantsCount = other.restaurantsCount;
	capacity = other.capacity;

	restaurants = nullptr;
	restaurantsCount = 0;
	capacity = 0;
}

void Foodpanda::free() {
	delete[] restaurants;
	restaurantsCount = 0;
	capacity = 0;
}

Foodpanda::Foodpanda() {
	restaurants = new Restaurant[capacity];
}

Foodpanda::Foodpanda(const Foodpanda& other) {
	copyFrom(other);
}

Foodpanda::Foodpanda(Foodpanda&& other) noexcept {
	moveFrom(std::move(other));
}

Foodpanda& Foodpanda::operator=(const Foodpanda& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Foodpanda& Foodpanda::operator=(Foodpanda&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Foodpanda::~Foodpanda() {
	free();
}

void Foodpanda::addProductToRestaurant(const MyString& product, size_t restaurantIndex) {
	if (restaurantIndex > restaurantsCount) {
		throw std::logic_error("Index surpasses the number of restaurants");
	}

	restaurants[restaurantIndex].addProduct(product);
}

void Foodpanda::resize() {
	capacity *= 1.5;

	Restaurant* newRestaurants = new Restaurant[capacity];
	for (size_t i = 0; i < capacity; i++) {
		newRestaurants[i] = restaurants[i];
	}

	delete[] restaurants;
	restaurants = newRestaurants;
}

void Foodpanda::addRestaurant(const Restaurant& newRestaurant) {
	restaurantsCount++;

	if (restaurantsCount >= capacity) {
		resize();
	}

	restaurants[restaurantsCount - 1] = newRestaurant;
}

void Foodpanda::addOrder(const Order& newOrder) {
	for (size_t i = 0; i < restaurantsCount; i++) {
		MyString restaurantName(restaurants[i].getName());

		if (restaurantName == newOrder.getRestaurantName()) {
			restaurants[i].recieveOrder(newOrder);
			return;
		}
	}

	throw std::logic_error("No restaurant found with the name on the order.");
}
