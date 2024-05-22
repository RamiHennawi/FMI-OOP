#include "Form.h"

Form::Form(const Form& other) {
	copyFrom(other);
}

Form::Form(Form&& other) noexcept {
	moveFrom(std::move(other));
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Form& Form::operator=(Form&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Form::~Form() {
	free();
}

void Form::copyFrom(const Form& other) {
	name = other.name;
	dimensions = other.dimensions;

	controlsCount = other.controlsCount;
	controlsCapacity = other.controlsCapacity;

	controls = new Control*[controlsCapacity];
	for (size_t i = 0; i < controlsCount; i++) {
		controls[i] = other.controls[i]->clone();
	}
}

void Form::moveFrom(Form&& other) noexcept {
	name = other.name;
	dimensions = other.dimensions;

	controls = other.controls;
	controlsCount = other.controlsCount;
	controlsCapacity = other.controlsCapacity;

	other.name = "";
	other.dimensions = { 0, 0 };

	other.controls = nullptr;
	other.controlsCount = 0;
	other.controlsCapacity = 0;

}

void Form::free() {
	for (size_t i = 0; i < controlsCount; i++) {
		delete controls[i];
	}

	delete[] controls;
	controls = nullptr;
}

void Form::resize() {
	controlsCapacity *= 2;

	Control** temp = new Control * [controlsCapacity];
	for (size_t i = 0; i < controlsCount; i++) {
		temp[i] = controls[i];
	}

	delete controls;
	controls = temp;
}
