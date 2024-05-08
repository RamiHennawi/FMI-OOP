#pragma once

namespace HelperFunctions {
	unsigned int getNextPowerOfTwo(unsigned int n);
}

class Vector {
private: 
	int* elements = nullptr;
	unsigned size = 0;
	unsigned capacity = 2;

	void copyFrom(const Vector& other);
	void free();

	void resize(unsigned lengthToFit);

public:
	Vector() = default;

	Vector(unsigned capacity);
	Vector(const int* newElements, unsigned newSize);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void push_back(int newElement);
	void pop_back(int newElement);
	void insert(size_t index, int element);
	void erase(size_t index);
	bool empty()
};

