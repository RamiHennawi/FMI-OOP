#include "PartialFunctionCollection.h"

void PartialFunctionCollection::resize() {
	capacity *= FUNCTION_COLLECTION_CONSTANTS::RESIZE_COEFFICIENT;
	
	PartialFunction** tempFunctions = new PartialFunction * [capacity];
	for (size_t i = 0; i < capacity; i++) {
		tempFunctions[i] = functions[i];
	}

	delete[] functions;
	functions = tempFunctions;
}

PartialFunctionCollection::PartialFunctionCollection() {
	functions = new PartialFunction* [capacity];
}

PartialFunctionCollection::PartialFunctionCollection(const PartialFunctionCollection& other) {
	copyFrom(other);
}

PartialFunctionCollection::PartialFunctionCollection(PartialFunctionCollection&& other) noexcept {
	moveFrom(std::move(other));
}

PartialFunctionCollection& PartialFunctionCollection::operator=(const PartialFunctionCollection& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

PartialFunctionCollection& PartialFunctionCollection::operator=(PartialFunctionCollection&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

PartialFunctionCollection::~PartialFunctionCollection() {
	free();
}

void PartialFunctionCollection::addFunction(const PartialFunction& function) {
	if (count == capacity) {
		resize();
	}

	functions[count++] = function.clone();
}

size_t PartialFunctionCollection::getCount() const {
	return count;
}

const PartialFunction& PartialFunctionCollection::getFunction(size_t index) const {
	return *functions[index];
}

const PartialFunction& PartialFunctionCollection::operator[](size_t index) const {
	return *functions[index];
}

void PartialFunctionCollection::moveFrom(PartialFunctionCollection&& other) noexcept {
	count = other.count;
	capacity = other.capacity;
	functions = other.functions;

	other.functions = nullptr;
	other.count = other.capacity = 0;
}

void PartialFunctionCollection::copyFrom(const PartialFunctionCollection& other) {
	count = other.count;
	capacity = other.capacity;

	functions = new PartialFunction* [capacity];
	for (size_t i = 0; i < count; i++) {
		functions[i] = other.functions[i]->clone();
	}
}

void PartialFunctionCollection::free() {
	for (size_t i = 0; i < count; i++) {
		delete functions[i];
	}

	delete[] functions;
	functions = nullptr;
	count = capacity = 0;
}
