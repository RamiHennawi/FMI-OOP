#include "Restaurant.h"
#pragma warning(disable: 4996)

void Restaurant::copyFrom(const Restaurant& other) {
	strcpy(name, other.name);

	productsCount = other.productsCount;
	capacity = other.capacity;

	products = new MyString[capacity];
	for (size_t i = 0; i < productsCount; i++) {
		products[i] = other.products[i];
	}
}

void Restaurant::moveFrom(Restaurant&& other) noexcept {
	strcpy(name, other.name);
	products = other.products;
	productsCount = other.productsCount;
	capacity = other.capacity;

	strcpy(other.name, "");
	products = nullptr;
	productsCount = 0;
	capacity = 0;
}

void Restaurant::free() {
	delete[] products;
	strcpy(name, "");
	productsCount = 0;
	capacity = 0;
}

Restaurant::Restaurant() {
	strcpy(name, "");

	products = new MyString[capacity];
}

Restaurant::Restaurant(const char* restaurantName) {
	strcpy(name, restaurantName);

	products = new MyString[capacity];
}

Restaurant::Restaurant(const Restaurant& other) {
	copyFrom(other);
}

Restaurant::Restaurant(Restaurant&& other) noexcept {
	moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(const Restaurant& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Restaurant::~Restaurant() {
	free();
}

void Restaurant::resize() {
	capacity *= 1.5;

	MyString* newProducts = new MyString[capacity];
	for (size_t i = 0; i < productsCount; i++) {
		newProducts[i] = products[i];
	}

	delete[] products;
	products = newProducts;
}

void Restaurant::addProduct(const MyString& newProduct) {
	productsCount++;

	if (productsCount >= capacity) {
		resize();
	}

	products[productsCount - 1] = newProduct;
}

bool Restaurant::hasProduct(const MyString& product) const {
	for (size_t i = 0; i < productsCount; i++) {
		if (product == products[i]) return true;
	}

	return false;
}

bool Restaurant::hasAllProducts(MyString* products, size_t productsCount) const {
	for (size_t i = 0; i < productsCount; i++) {
		if(!hasProduct(products[i])) return false;
	}

	return true;
}

void Restaurant::recieveOrder(const Order& order) {
	MyString restaurantName(name);

	if (order.getRestaurantName() != restaurantName) {
		throw std::logic_error("Restaurant name doesn't match the one in the order.");
	}
	else if (!hasAllProducts(order.getProducts(), order.getProductsCount())) {
		throw std::logic_error("Restaurant doesn't offer some of the products in the order.");
	}
}

const char* Restaurant::getName() const {
	return name;
}
