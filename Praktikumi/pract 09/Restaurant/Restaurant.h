#pragma once
#include "MyString.h"
#include "Order.h"

constexpr size_t MAX_RESTAURANT_NAME_SIZE = 25;

class Restaurant {
public:
	Restaurant();
	Restaurant(const char* restaurantName);
	Restaurant(const Restaurant& other);
	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(const Restaurant& other);
	Restaurant& operator=(Restaurant&& other) noexcept;
	~Restaurant();

	void addProduct(const MyString& newProduct);
	void recieveOrder(const Order& order);

	const char* getName() const;

private:
	char name[MAX_RESTAURANT_NAME_SIZE] = "";
	MyString* products = nullptr;
	size_t productsCount = 0;
	size_t capacity = 16;

	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other) noexcept;
	void free();

	void resize();

	bool hasProduct(const MyString& product) const;
	bool hasAllProducts(MyString* products, size_t productsCount) const;
};

