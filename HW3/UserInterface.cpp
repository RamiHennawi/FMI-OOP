#include "UserInterface.h"
#include "PartialFunctionFactory.h"

constexpr size_t BUFFER_SIZE = 100;

namespace HelperFunctions {
	int32_t convertToInt(const char* num) {
		int32_t result = 0;

		for (size_t i = 0; num[i] != '\0'; i++) {
			if (num[i] < '0' || num[i] > '9') {
				throw std::invalid_argument("Invalid input.");
			}

			result = result * 10 + (num[i] - '0');
		}
	
		return result;
	}
}

void UserInterface::start() const {
	std::cout << "Welcome to Partial Functions!\n";
	std::cout << "First, give me the name of the data file\n--> ";

	char buffer[BUFFER_SIZE];
	std::cin >> buffer;

	PartialFunction* func = partialFunctionFactory(buffer);

	std::cout << "\nCool! Now, choose one of the following work flows:\n1. Print function values in closed interval\n"
		<< "2. Generate function values after each input you give\n--> ";

	short flow;
	std::cin >> flow;

	if (flow == 1) {
		std::cout << "\nGood! Enter a and b in [a, b]: ";

		int32_t a, b;
		while (true) {
			std::cin >> a >> b;

			if (a > b) {
				std::cout << "Invalid input. Try again.\n";
			}
			else {
				break;
			}
		}

		for (int32_t i = a; i <= b; i++) {

			std::cout << "f(" << i << ") = ";

			try {
				std::cout << func->operator()(i).getSecond() << std::endl;
			}
			catch (std::invalid_argument& e) {
				std::cout << "undefined" << std::endl;
			}
		}
	}
	else if (flow == 2) {
		std::cout << "\nAwesome! Start inputting numbers. To end enter something other than a number.\n";

		char numberBuffer[BUFFER_SIZE];
		int32_t number;

		while (true) {
			std::cin >> numberBuffer;

			try {
				number = HelperFunctions::convertToInt(numberBuffer);
			}
			catch (std::invalid_argument& e) {
				return;
			}

			std::cout << "f(" << number << ") = ";

			try {
				std::cout << func->operator()(number).getSecond() << std::endl;
			}
			catch (std::invalid_argument& e) {
				std::cout << "undefined" << std::endl;
			}
		}
	}
	else {
		std::cout << "Invalid input. Try again.\n";
		std::cin >> flow;
	}
}
