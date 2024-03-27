#pragma once
#include "State.h"
#include "Price.h"

constexpr size_t MAX_PRICES_SIZE = 50;

class PricesDatabase {
	size_t size = 0;
	Price prices[MAX_PRICES_SIZE] = {};

public:
	PricesDatabase();

	State addPrice(size_t productId, double price);
	double getPrice(size_t productId) const;
};