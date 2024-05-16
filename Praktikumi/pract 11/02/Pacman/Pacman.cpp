#include "Pacman.h"
#pragma warning(disable: 4996)

Pacman::Pacman() {
	points = 150;

	vizFile = new char[strlen("Pacman.txt") + 1];
	strcpy(vizFile, "Pacman.txt");
}

void Pacman::visualize() {
	char* filePath = new char[strlen(vizDirectory) + strlen(vizFile) + 1];
	strcpy(filePath, vizDirectory);
	strcat(filePath, vizFile);

	std::ifstream in(filePath, std::ios::in);

	if (!in.is_open()) {
		throw std::runtime_error("Could not open Pacman visualization file.");
	}

	while (!in.eof()) {
		char buffer[MAX_BUFFER_SIZE];
		in.getline(buffer, MAX_BUFFER_SIZE);
		std::cout << buffer << std::endl;
	}

	in.close();
}
