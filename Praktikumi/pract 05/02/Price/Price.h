#pragma once
#include "State.h"

class Price {
	size_t productId = 0;
	double price = 0;

public:
	Price();
	
	Price(size_t productId, double price);

	double getPrice() const;
	size_t getId() const;

	State updatePrice(double amount);
};