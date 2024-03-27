#pragma once
#include "State.h";
#include "Product.h";

constexpr size_t MAX_PRODUCTS_SIZE = 50;

class ProductsDatabase {
	size_t size = 0;
	Product products[MAX_PRODUCTS_SIZE] = {};

public:
	ProductsDatabase();

	State addProduct(const char* name, size_t ownerID, size_t productID, size_t quantity);
	size_t itemsOwned(size_t id, size_t productID) const;
	State update(size_t ownerID, size_t productID, int update);
	const char* getProductName(size_t productID) const;
	bool existsProduct(size_t id) const;
	bool existsUserWithProduct(size_t ownerID, size_t productID);
};