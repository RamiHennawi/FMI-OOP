#include "Order.h"

void Order::copyFrom(const Order& other) {
	productsCount = other.productsCount;
	capacity = other.capacity;
	restaurant = other.restaurant;

	products = new MyString[productsCount];
	for (int i = 0; i < productsCount; i++) {
		products[i] = other.products[i];
	}
}

void Order::moveFrom(Order&& other) noexcept {
	productsCount = other.productsCount;
	capacity = other.capacity;
	restaurant = std::move(other.restaurant);
	products = other.products;

	other.productsCount = 0;
	other.capacity = 0;
	other.products = nullptr;
}

void Order::free() {
	delete[] products;
	restaurant = "";
	productsCount = 0;
	capacity = 0;
}

Order::Order(MyString restaurant) {
	this->restaurant = restaurant;
}

Order::Order(const Order& other) {
	copyFrom(other);
}

Order::Order(Order&& other) noexcept {
	moveFrom(std::move(other));
}

Order& Order::operator=(const Order& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Order& Order::operator=(Order&& other) noexcept {
	if (this != &other) {
		free();
		copyFrom(std::move(other));
	}

	return *this;
}

Order::~Order() {
	free();
}

void Order::resize() {
	capacity *= 1.5;

	MyString* newProducts = new MyString[capacity];
	for (size_t i = 0; i < capacity; i++) {
		newProducts[i] = products[i];
	}

	delete[] products;
	products = newProducts;
}

void Order::addProduct(MyString newProduct) {
	productsCount++;

	if (productsCount >= capacity) {
		resize();
	}

	products[productsCount - 1] = newProduct;
}

unsigned Order::getDeliveryTime() const {
	unsigned time = 0;

	for (size_t i = 0; i < productsCount; i++) {
		time += products[i].getLength();
	}
	time += productsCount;

	return time;
}
