#pragma once
#include "UsersDatabase.h"
#include "ProductsDatabase.h"
#include "PricesDatabase.h"

class SalesSystem {
private:
	UsersDatabase users;
	ProductsDatabase products;
	PricesDatabase prices;

public:
	SalesSystem();

	void addUser(size_t id, double balance, const char* name);
	State addProduct(const char* name, size_t ownerID, size_t productID, size_t quantity);
	State addPrice(size_t productId, double price);
	State sell(size_t idFrom, size_t idTo, size_t productID, size_t quantity);
};
