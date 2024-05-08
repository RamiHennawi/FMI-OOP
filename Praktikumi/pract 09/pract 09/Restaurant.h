#pragma once
#include "MyString.h"

constexpr size_t MAX_RESTAURANT_NAME_SIZE = 25;

class Restaurant {
	char name[MAX_RESTAURANT_NAME_SIZE] = "";
	MyString* products = nullptr;
	size_t productsCount = 0;
	size_t capacity = 16;

public:
	Restaurant(MyString restaurant);
	Restaurant(const Restaurant& other);
	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(const Restaurant& other);
	Restaurant& operator=(Restaurant&& other) noexcept;
	~Restaurant();

	void addProduct(MyString newProduct);
};

