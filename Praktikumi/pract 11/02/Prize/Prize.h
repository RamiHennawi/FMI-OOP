#pragma once
#include <iostream>
#include <fstream>

constexpr size_t MAX_BUFFER_SIZE = 1024;

class Prize {
public:
	Prize() = default;

	virtual void visualize() = 0; // malko e bezmisleno ama za trenirovka ig

protected:
	unsigned points = 0;
	const char* vizDirectory = "./viz/";
	char* vizFile = nullptr;
};
