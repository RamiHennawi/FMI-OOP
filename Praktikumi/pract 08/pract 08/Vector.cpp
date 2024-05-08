#include "Vector.h"
#include <iostream>


namespace HelperFunctions {
	unsigned int getNextPowerOfTwo(unsigned int n) {
		unsigned int step = 1;

		while ((n >> step) > 0) {
			n |= n >> step;
			step *= 2;
		}

		return n + 1;
	}
}

using namespace HelperFunctions;

void Vector::copyFrom(const Vector& other) {
	size = other.size;
	capacity = other.capacity;

	elements = new int[capacity];
	for (int i = 0; i < size; i++) {
		elements[i] = other.elements[i];
	}
}

void Vector::free() {
	delete[] elements;
	size = 0;
	capacity = 2;
}

Vector::Vector(unsigned capacity) {
	this->capacity = capacity;

	elements = new int[capacity] { 0 };
}

Vector::Vector(const int* newElements, unsigned newSize) {
	size = newSize;
	capacity = getNextPowerOfTwo(newSize);

	elements = new int[capacity] { 0 };
	for (int i = 0; i < size; i++) {
		elements[i] = newElements[i];
	}
}

Vector::Vector(const Vector& other) {
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Vector::~Vector() {
	free();
}

void Vector::resize(unsigned lengthToFit) {
	capacity *= 2;

	int* newElements = new int[capacity] { 0 };
	for (int i = 0; i < size; i++) {
		newElements[i] = elements[i];
	}
	delete[] elements;

	elements = newElements;
}

void Vector::push_back(int newElement) {
	size++;
	if (size >= capacity) {
		resize(size);
	}

	elements[size] = newElement;
}

void Vector::pop_back(int newElement) {
	if (empty()) {
		throw "Empty vector";
	}

	elements[size--] = 0;
}

void Vector::insert(size_t index, int element) {
	if (size < index) {
		throw "Index outside of vector size";
	}

	size++;
	if (size >= capacity) {
		resize(size);
	}

	for (int i = size - 1; i > index; i--) {
		elements[i] = elements[i - 1];
	}
	elements[index] = element;
}

void Vector::erase(size_t index) {
	if (size < index) {
		throw "Index outside of vector size";
	}

	elements[index] = 0;
}
