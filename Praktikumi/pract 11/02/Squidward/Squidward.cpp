#include "Squidward.h"
#pragma warning(disable: 4996)

Squidward::Squidward() {
	points = 1500;

	vizFile = new char[strlen("Squidward.txt") + 1];
	strcpy(vizFile, "Squidward.txt");
}

void Squidward::visualize() {
	char* filePath = new char[strlen(vizDirectory) + strlen(vizFile) + 1];
	strcpy(filePath, vizDirectory);
	strcat(filePath, vizFile);

	std::ifstream in(filePath, std::ios::in);

	if (!in.is_open()) {
		throw std::runtime_error("Could not open Sylvester visualization file.");
	}

	while (!in.eof()) {
		char buffer[MAX_BUFFER_SIZE];
		in.getline(buffer, MAX_BUFFER_SIZE);
		std::cout << buffer << std::endl;
	}

	in.close();
}
