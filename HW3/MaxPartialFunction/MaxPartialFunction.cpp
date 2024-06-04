#include "MaxPartialFunction.h"

MaxPartialFunction::MaxPartialFunction(const PartialFunctionCollection& collection) : ExtremalPartialFunction(collection) {}

Pair<bool, int32_t> MaxPartialFunction::operator()(int32_t x) const {
	if (!isDefinedIn(x)) {
		return Pair<bool, int32_t>(0, 0);
	}

	int32_t tempMax = INT32_MIN;

	for (size_t i = 0; i < collection.getCount(); i++) {
		if (tempMax < collection.getFunction(i).operator()(x).getSecond()) {
			tempMax = collection.getFunction(i).operator()(x).getSecond();
		}
	}
	
	return Pair<bool, int32_t>(true, tempMax);
}

PartialFunction* MaxPartialFunction::clone() const {
	return new MaxPartialFunction(*this);
}
