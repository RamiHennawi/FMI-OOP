#include "PartialFunctionFactory.h"
#include "Function.h"
#include "PartialFunctionCollection.h"
#include "MinPartialFunction.h"
#include "MaxPartialFunction.h"
#include "PartialFunctionByCriteria.hpp"

#include <iostream>
#include <fstream>

PartialFunction* partialFunctionFactory(const char* fileName) {
	std::ifstream in(fileName, std::ios::in | std::ios::binary);

	if (!in.is_open()) {
		throw std::runtime_error("Could not open source file.");
	}

	int32_t num, type;
	in.read(reinterpret_cast<char*>(&num), sizeof(int32_t));
	in.read(reinterpret_cast<char*>(&type), sizeof(int32_t));

	switch (type) {
	case 0: {
		Function f(in, num, 0);
		return new PartialFunctionByCriteria<Function>(f);

		break;
	}
	case 1: {
		Function f(in, num, 1);
		return new PartialFunctionByCriteria<Function>(f);

		break;
	}
	case 2: {
		Function f(in, num, 2);
		return new PartialFunctionByCriteria<Function>(f);

		break;
	}
	case 3: {
		PartialFunctionCollection collection;

		while (true) {
			char buffer[100];
			in.read(reinterpret_cast<char*>(&buffer), 100);

			if (in.eof()) {
				break;
			}

			PartialFunction* newFunc = partialFunctionFactory(buffer);
			collection.addFunction(*newFunc);
		}

		return new MaxPartialFunction(collection);

		break;
	}
	case 4: {
		PartialFunctionCollection collection;

		while (true) {
			char buffer[100];
			in.read(reinterpret_cast<char*>(&buffer), 100);

			if (in.eof()) {
				break;
			}

			collection.addFunction(*partialFunctionFactory(buffer));
		}

		return new MinPartialFunction(collection);

		break;
	}
	default: {
		in.close();
		throw std::invalid_argument("Invalid file type.");
	}
	}

	in.close();
}