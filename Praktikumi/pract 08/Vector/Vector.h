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

	void resize_up();
	void resize_down();

public:
	Vector() = default;

	Vector(unsigned capacity);
	Vector(const int* newElements, unsigned newSize);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void push_back(int newElement);
	void pop_back();
	void insert(size_t index, int element);
	void erase(size_t index);
	void clear();

	bool isEmpty() const;

	void print() const;
};

// mnogo ne znam kak bachka tova s erase, slojim gi da sa nuli vse edno, da kajem ok :)
