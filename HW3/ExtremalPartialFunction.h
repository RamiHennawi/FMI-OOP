#pragma once
#include "PartialFunctionCollection.h"
#include "Pair.hpp"

class ExtremalPartialFunction : public PartialFunction {
public:
	ExtremalPartialFunction(const PartialFunctionCollection&);

	virtual ~ExtremalPartialFunction() = default;

	bool isDefinedIn(int32_t) const override;

protected:
	PartialFunctionCollection collection;
};
