#pragma once
#include "CarPart.h"

class Battery : public CarPart {
public:
	Battery(unsigned capacity, const char* id);
	Battery(const char* manufacturer, const char* description, unsigned capacity, const char* id);

	Battery(const Battery& other);
	Battery(Battery&& other) noexcept;
	Battery& operator=(const Battery& other);
	Battery& operator=(Battery&& other) noexcept;
	~Battery();

	friend std::ostream& operator<<(std::ostream& os, const Battery& obj);

private:
	unsigned capacity; // in Ah
	char* id;

	void copyFrom(const Battery& other);
	void moveFrom(Battery&& other) noexcept;
	void free();
};
