#include "ExtremalPartialFunction.h"

ExtremalPartialFunction::ExtremalPartialFunction(const PartialFunctionCollection& collection) : collection(collection) {}

bool ExtremalPartialFunction::isDefinedIn(int32_t x) const {
	size_t functionCount = collection.getCount();

	if (functionCount == 0) {
		throw std::length_error("Collection of functions is empty.\n");
	}

	for (size_t i = 0; i < functionCount; i++) {
		if (!collection.getFunction(i).isDefinedIn(x)) {
			return false;
		}
	}

	return true;
}
