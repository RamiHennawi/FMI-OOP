#include "MinPartialFunction.h"

MinPartialFunction::MinPartialFunction(const PartialFunctionCollection& collection) : ExtremalPartialFunction(collection) {}

Pair<bool, int32_t> MinPartialFunction::operator()(int32_t x) const {
	if (!isDefinedIn(x)) {
		throw std::invalid_argument("Function is not defined in that point.");
	}

	int32_t tempMin = INT32_MAX;

	for (size_t i = 0; i < collection.getCount(); i++) {
		if (tempMin > collection.getFunction(i).operator()(x).getSecond()) {
			tempMin = collection.getFunction(i).operator()(x).getSecond(); // is it abstract enough??
		}
	}

	return Pair<bool, int32_t>(true, tempMin);
}

PartialFunction* MinPartialFunction::clone() const
{
	return new MinPartialFunction(*this);
}