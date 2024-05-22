#pragma once
#include "MyString.h"

struct Point {
	unsigned x = 0, y = 0;
};

struct Dimensions {
	unsigned width = 0, height = 0;
};

class Control {
public:
	virtual ~Control() = default;

	void setControlDimensions(unsigned width, unsigned height);
	void setControl(unsigned x, unsigned y, unsigned width, unsigned height);

	virtual void setDataDialog() = 0;
	virtual Control* clone() const = 0;

private:
	Point location;
	Dimensions size;
};
