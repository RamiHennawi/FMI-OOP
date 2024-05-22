#include "Label.h"

Control* Label::clone() const {
	return new Label(*this);
}

void Label::setDataDialog() {
	std::cout << "Input new text for the label: ";
	
	MyString input;
	std::cin >> input;

	text = input;
}

void Label::changeText(MyString newText) {
	text = newText;
}
