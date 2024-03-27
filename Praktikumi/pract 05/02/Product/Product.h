#pragma once
#include "State.h";

constexpr size_t MAX_NAME_SIZE = 32;

class Product {
	size_t ownerId = 0;
	size_t quantity = 0;
	size_t productId = 0;
	char name[MAX_NAME_SIZE + 1] = "";

public:
	Product();

	Product(size_t ownerId, size_t quantity, size_t productId, const char* name);

	size_t getQuantity() const;
	size_t getProductID() const;
	size_t getOwnerID() const;
	const char* getName() const;
	State updateQuantity(int amount);
};