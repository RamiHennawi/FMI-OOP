#include "Function.h"

Function::Function(std::ifstream& in, uint16_t n, uint16_t t) : values(FUNCTION_SIZE) {
	switch (t) {
	case 0: {
		functionTypeZero(in, n);
		break;
	}
	case 1: {
		functionTypeOne(in, n);
		break;
	}
	case 2: {
		functionTypeTwo(in, n);
		break;
	}
	default: {
		throw std::invalid_argument("Invalid number for function type.\n");
	}
	}
}

bool Function::isDefinedIn(int32_t x) const {
	return values[x + FUNCTION_TRANSLATION_RATE].getFirst();
}

Pair<bool, int32_t> Function::operator()(int32_t x) const {
	if (!isDefinedIn(x)) {
		return Pair<bool, int32_t>(0, 0);
	}
	
	return values[x + FUNCTION_TRANSLATION_RATE];
}

void Function::functionTypeZero(std::ifstream& in, uint16_t n) {
	int32_t* arguments = new int32_t[n];
	int32_t* results = new int32_t[n];

	int32_t fileNumber;

	for (size_t i = 0; i < n; i++) {
		in.read(reinterpret_cast<char*>(&fileNumber), sizeof(int32_t));

		arguments[i] = fileNumber;
	}

	for (size_t i = 0; i < n; i++) {
		in.read(reinterpret_cast<char*>(&fileNumber), sizeof(int32_t));

		results[i] = fileNumber;
	}

	for (uint32_t i = 0; i < FUNCTION_SIZE; i++) {
		int32_t argumentIndex = -1;

		for (uint32_t j = 0; j < n; j++) {
			if (arguments[j] == (i - FUNCTION_TRANSLATION_RATE)) {
				argumentIndex = j;
				break;
			}
		}

		// specific for the function type (pair)
		if (argumentIndex != -1) {
			values.pushBack(Pair<bool, int32_t>(true, results[argumentIndex]));
		}
		else {
			values.pushBack(Pair<bool, int32_t>(false, 0));
		}
	}

	delete[] arguments;
	delete[] results;
}

void Function::functionTypeOne(std::ifstream& in, uint16_t n) {
	int32_t* arguments = new int32_t[n];

	int32_t fileNumber;

	for (size_t i = 0; i < n; i++) {
		in.read(reinterpret_cast<char*>(&fileNumber), sizeof(int32_t));

		arguments[i] = fileNumber;
	}

	for (uint32_t i = 0; i < FUNCTION_SIZE; i++) {
		bool isNotDefined = false;

		for (uint32_t j = 0; j < n; j++) {
			if (arguments[j] == (i - FUNCTION_TRANSLATION_RATE)) {
				isNotDefined = true;
				break;
			}
		}

		// specific for the function type (identity)
		if (isNotDefined) {
			values.pushBack(Pair<bool, int32_t>(false, 0));
		}
		else {
			values.pushBack(Pair<bool, int32_t>(true, i - FUNCTION_TRANSLATION_RATE));
		}
	}

	delete[] arguments;
}

void Function::functionTypeTwo(std::ifstream& in, uint16_t n) {
	int32_t* arguments = new int32_t[n];

	int32_t fileNumber;

	for (size_t i = 0; i < n; i++) {
		in.read(reinterpret_cast<char*>(&fileNumber), sizeof(int32_t));

		arguments[i] = fileNumber;
	}

	for (uint32_t i = 0; i < FUNCTION_SIZE; i++) {
		bool isSpecified = false;

		for (uint32_t j = 0; j < n; j++) {
			if (arguments[j] == (i - FUNCTION_TRANSLATION_RATE)) {
				isSpecified = true;
				break;
			}
		}

		// specific for the function type (bool)
		if (isSpecified) {
			values.pushBack(Pair<bool, int32_t>(true, 1));
		}
		else {
			values.pushBack(Pair<bool, int32_t>(true, 0));
		}
	}

	delete[] arguments;
}
