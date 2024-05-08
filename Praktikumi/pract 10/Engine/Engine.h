#pragma once
#include "CarPart.h"

class Engine : public CarPart {
public:
	Engine(unsigned horsePower);
	Engine(const char* manufacturer, const char* description, unsigned horsePower);

	unsigned getHorsePower() const;

	friend std::ostream& operator<<(std::ostream& os, const Engine& obj);

private:
	unsigned horsePower;
};
