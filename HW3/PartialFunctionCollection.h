#pragma once
#include "PartialFunction.h"

namespace FUNCTION_COLLECTION_CONSTANTS {
	constexpr size_t INITIAL_CAPACITY = 8;
	constexpr size_t RESIZE_COEFFICIENT = 2;
}

// used to store collections for extremal functions
class PartialFunctionCollection {
private:
	PartialFunction** functions = nullptr;
	size_t count = 0;
	size_t capacity = FUNCTION_COLLECTION_CONSTANTS::INITIAL_CAPACITY;

	void resize();

public:
	PartialFunctionCollection();
	PartialFunctionCollection(const PartialFunctionCollection&);
	PartialFunctionCollection(PartialFunctionCollection&&) noexcept;

	PartialFunctionCollection& operator=(const PartialFunctionCollection&);
	PartialFunctionCollection& operator=(PartialFunctionCollection&&) noexcept;

	~PartialFunctionCollection();

	void addFunction(const PartialFunction&);

	size_t getCount() const;
	const PartialFunction& getFunction(size_t) const; // alternative to operator[]

	const PartialFunction& operator[](size_t) const;

private:
	void moveFrom(PartialFunctionCollection&&) noexcept;
	void copyFrom(const PartialFunctionCollection&);
	void free();
};
