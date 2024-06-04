#include "ExtremalPartialFunction.h"

ExtremalPartialFunction::ExtremalPartialFunction(const PartialFunctionCollection& collection) : collection(collection) {}

bool ExtremalPartialFunction::isDefinedIn(int32_t x) const {
	for (size_t i = 0; i < collection.getCount(); i++) {
		if (!collection.getFunction(i).isDefinedIn(x)) {

			return false;
		}
	}

	return true;
}
