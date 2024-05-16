#include "Penguin.h"
#pragma warning(disable: 4996)

Penguin::Penguin() {
	points = 50;

	vizFile = new char[strlen("Penguin.txt") + 1];
	strcpy(vizFile, "Penguin.txt");
}

void Penguin::visualize() {
	char* filePath = new char[strlen(vizDirectory) + strlen(vizFile) + 1];
	strcpy(filePath, vizDirectory);
	strcat(filePath, vizFile);

	std::ifstream in(filePath, std::ios::in);

	if (!in.is_open()) {
		throw std::runtime_error("Could not open Penguin visualization file.");
	}

	while (!in.eof()) {
		char buffer[MAX_BUFFER_SIZE];
		in.getline(buffer, MAX_BUFFER_SIZE);
		std::cout << buffer << std::endl;
	}

	in.close();
}
