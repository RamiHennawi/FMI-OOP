#pragma once
#include "ExtremalPartialFunction.h"

class MaxPartialFunction : public ExtremalPartialFunction {
public:
	MaxPartialFunction(const PartialFunctionCollection&);

	Pair<bool, int32_t> operator()(int32_t) const override;

	PartialFunction* clone() const override;
};
