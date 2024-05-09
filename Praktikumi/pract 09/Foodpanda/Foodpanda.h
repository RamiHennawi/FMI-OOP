#pragma once
#include "Restaurant.h"

class Foodpanda {
public:
	Foodpanda();
	Foodpanda(const Foodpanda& other);
	Foodpanda(Foodpanda&& other) noexcept;
	Foodpanda& operator=(const Foodpanda& other);
	Foodpanda& operator=(Foodpanda&& other) noexcept;
	~Foodpanda();

	void addProductToRestaurant(const MyString& product, size_t restaurantIndex);
	void addRestaurant(const Restaurant& newRestaurant);
	void addOrder(const Order& newOrder);

private:
	Restaurant* restaurants = nullptr;
	size_t restaurantsCount = 0;
	size_t capacity = 16;

	void copyFrom(const Foodpanda& other);
	void moveFrom(Foodpanda&& other) noexcept;
	void free();

	void resize();
};

