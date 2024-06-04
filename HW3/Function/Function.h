#pragma once
#include <iostream>
#include <fstream>
#include "Pair.hpp"
#include "Vector.hpp"

constexpr uint32_t FUNCTION_SIZE = 301;
constexpr int32_t FUNCTION_TRANSLATION_RATE = 150;

class Function {
private:
	Vector<Pair<bool, int32_t>> values;

	void functionTypeZero(std::ifstream&, uint16_t);
	void functionTypeOne(std::ifstream&, uint16_t);
	void functionTypeTwo(std::ifstream&, uint16_t);

public:
	Function(std::ifstream&, uint16_t, uint16_t);

	bool isDefinedIn(int32_t) const;
	Pair<bool, int32_t> operator()(int32_t) const;
};

