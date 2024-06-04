#pragma once
#include "Pair.hpp"
#include "PartialFunction.h"

template <typename T>
class PartialFunctionByCriteria : public PartialFunction {
private:
	T function;

public:
	PartialFunctionByCriteria(const T&);

	Pair<bool, int32_t> operator()(int32_t) const override;
	bool isDefinedIn(int32_t) const override;

	PartialFunction* clone() const override;
};

template <typename T>
PartialFunctionByCriteria<T>::PartialFunctionByCriteria(const T& obj) : function(obj) {}

template <typename T>
Pair<bool, int32_t> PartialFunctionByCriteria<T>::operator()(int32_t x) const {
	if (isDefinedIn(x)) {
		return function(x);
	}
	else {
		throw std::invalid_argument("Function is not defined in that point.");
	}
}

template <typename T>
bool PartialFunctionByCriteria<T>::isDefinedIn(int32_t x) const {
	return function(x).getFirst();
}

template <typename T>
PartialFunction* PartialFunctionByCriteria<T>::clone() const {
	return new PartialFunctionByCriteria(*this);
}
