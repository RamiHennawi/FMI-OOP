#pragma once
#include <iostream>
#include <fstream>
#include "Pair.hpp"
#include "Vector.hpp"

constexpr int32_t FUNCTION_SIZE = 33;
constexpr int32_t FUNCTION_TRANSLATION_RATE = 12;

class Function {
private:
	Vector<Pair<bool, int32_t>> values;

	void functionTypeZero(std::ifstream&, int32_t);
	void functionTypeOne(std::ifstream&, int32_t);
	void functionTypeTwo(std::ifstream&, int32_t);

public:
	Function(std::ifstream&, int32_t, int32_t);

	bool isDefinedIn(int32_t) const;
	Pair<bool, int32_t> operator()(int32_t) const;

	void print() const;
};

