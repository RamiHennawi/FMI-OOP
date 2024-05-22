#include "CheckBox.h"

Control* CheckBox::clone() const {
	return new CheckBox(*this);
}

void CheckBox::setDataDialog() {
	state = !state;
}
