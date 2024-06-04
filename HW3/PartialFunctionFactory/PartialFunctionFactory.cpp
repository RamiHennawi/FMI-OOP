#include "PartialFunctionFactory.h"
#include "Function.h"
#include "PartialFunctionCollection.h"
#include "MinPartialFunction.h"
#include "MaxPartialFunction.h"
#include "PartialFunctionByCriteria.hpp"

#include <iostream>
#include <fstream>

constexpr size_t BUFF_SIZE = 100;
constexpr uint16_t MAX_NUM_FILE_VALUE = 32;

PartialFunction* partialFunctionFactory(const char* fileName) {
	std::ifstream in(fileName, std::ios::in | std::ios::binary);

	if (!in.is_open()) {
		throw std::runtime_error("Could not open source file.\n");
	}

	uint16_t num, type;
	in.read(reinterpret_cast<char*>(&num), sizeof(uint16_t));
	in.read(reinterpret_cast<char*>(&type), sizeof(uint16_t));

	if (num > MAX_NUM_FILE_VALUE) {
		throw std::invalid_argument("Number in file exceeds limit.\n");
	}

	// create the proper function according to the type (t)
	switch (type) {
	case 0: {
		Function f(in, num, 0);
		return new PartialFunctionByCriteria<Function>(f);
	}
	case 1: {
		Function f(in, num, 1);
		return new PartialFunctionByCriteria<Function>(f);
	}
	case 2: {
		Function f(in, num, 2);
		return new PartialFunctionByCriteria<Function>(f);
	}
	case 3: {
		PartialFunctionCollection collection;

		while (true) {
			char buffer[BUFF_SIZE];
			in.read(reinterpret_cast<char*>(&buffer), BUFF_SIZE);

			if (in.eof()) {
				break;
			}

			PartialFunction* newFunc = partialFunctionFactory(buffer);
			collection.addFunction(*newFunc);
		}

		return new MaxPartialFunction(collection);
	}
	case 4: {
		PartialFunctionCollection collection;

		while (true) {
			char buffer[BUFF_SIZE];
			in.read(reinterpret_cast<char*>(&buffer), BUFF_SIZE);

			if (in.eof()) {
				break;
			}

			collection.addFunction(*partialFunctionFactory(buffer));
		}

		return new MinPartialFunction(collection);
	}
	default: {
		in.close();
		throw std::invalid_argument("Invalid number for function type.\n");
	}
	}

	in.close();
}