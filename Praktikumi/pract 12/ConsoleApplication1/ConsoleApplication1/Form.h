#pragma once
#include "MyString.h"
#include "Control.h"

class Form {
public:
	Form() = default;
	Form(const Form& other);
	Form(Form&& other) noexcept;
	Form& operator=(const Form& other);
	Form& operator=(Form&& other) noexcept;
	~Form();

private:
	MyString name;
	Dimensions dimensions;
	Control** controls = nullptr;
	size_t controlsCount = 0;
	size_t controlsCapacity = 8;

	void resize();

	void copyFrom(const Form& other);
	void moveFrom(Form&& other) noexcept;
	void free();
};
