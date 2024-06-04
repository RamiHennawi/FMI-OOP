#include "MinPartialFunction.h"

MinPartialFunction::MinPartialFunction(const PartialFunctionCollection& collection) : ExtremalPartialFunction(collection) {}

Pair<bool, int32_t> MinPartialFunction::operator()(int32_t x) const {
	if (!isDefinedIn(x)) {
		return Pair<bool, int32_t>(0, 0);
	}

	int32_t tempMin = INT32_MAX;

	for (size_t i = 0; i < collection.getCount(); i++) {
		if (tempMin > collection.getFunction(i).operator()(x).getSecond()) {
			tempMin = collection.getFunction(i).operator()(x).getSecond();
		}
	}

	return Pair<bool, int32_t>(true, tempMin);
}

PartialFunction* MinPartialFunction::clone() const {
	return new MinPartialFunction(*this);
}