#pragma once
#include "Control.h"

class Label : public Control {
public:
	void setDataDialog() override;
	Control* clone() const override;

	void changeText(MyString newText);

private:
	MyString text;
};
