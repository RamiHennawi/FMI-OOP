#pragma once
#include "Control.h"

class CheckBox : public Control {
public:
	void setDataDialog() override;
	Control* clone() const override;

private:
	MyString text;
	bool state = false;
};
