#pragma once
#include "ExtremalPartialFunction.h"

class MinPartialFunction : public ExtremalPartialFunction {
public:
	MinPartialFunction(const PartialFunctionCollection&);

	Pair<bool, int32_t> operator()(int32_t) const override;
	PartialFunction* clone() const override;
};
