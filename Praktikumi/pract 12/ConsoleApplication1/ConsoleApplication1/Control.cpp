#include "Control.h"

void Control::setControlDimensions(unsigned width, unsigned height) {
	size.width = width;
	size.height = height;
}

void Control::setControl(unsigned x, unsigned y, unsigned width, unsigned height) {
	location.x = x;
	location.y = y;

	size.width = width;
	size.height = height;
}
