#pragma once
#include <iostream>

class CarPart {
public:
	CarPart(const char* manufacturer, const char* description);
	CarPart(const CarPart& other);
	CarPart(CarPart&& other) noexcept;
	CarPart& operator=(const CarPart& other);
	CarPart& operator=(CarPart&& other) noexcept;
	~CarPart();

	friend std::ostream& operator<<(std::ostream& os, const CarPart& obj);

private:
	unsigned id = 0;
	char* manufacturerName = nullptr;
	char* description = nullptr;

	static unsigned createdObjects;

	void copyFrom(const CarPart& other);
	void moveFrom(CarPart&& other) noexcept;
	void free();

	void copyManufacturer(const CarPart& other);
	void copyDescription(const CarPart& other);
};
