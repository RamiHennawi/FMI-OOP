#pragma once
#include "MyString.h"

class Order {
	MyString restaurant;
	MyString* products = nullptr;
	size_t productsCount = 0;
	size_t capacity = 16;

public:
	Order() = default;
	Order(MyString restaurant);
	Order(const Order& other);
	Order(Order&& other) noexcept;
	Order& operator=(const Order& other);
	Order& operator=(Order&& other) noexcept;
	~Order();

	void addProduct(MyString newProduct);
	unsigned getDeliveryTime() const;

private:
	void copyFrom(const Order& other);
	void moveFrom(Order&& other) noexcept;
	void free();

	void resize();
	
};

