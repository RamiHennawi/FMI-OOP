#include <iostream>
#include <exception>
#include "UserInterface.h"

int main() {
	UserInterface ui;

	try {
		ui.start();
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}
