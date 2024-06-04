#pragma once
#include "Pair.hpp"
#include <iostream>

class PartialFunction {
public:
	virtual ~PartialFunction() = default;

	virtual Pair<bool, int32_t> operator()(int32_t) const = 0;
	virtual bool isDefinedIn(int32_t) const = 0;

	virtual PartialFunction* clone() const = 0;
};