#include "Matrix.h"

void Matrix::initMatrix(size_t rows, size_t cols) {
	matrix = new int* [rows];

	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
}

void Matrix::copyFrom(const Matrix& other) {
	if (!other.matrix || other.rows < 2 || other.cols < 2) {
		return;
	}

	rows = other.rows;
	cols = other.cols;

	initMatrix(rows, cols);
}

void Matrix::free() {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
}

Matrix::Matrix(size_t rows, size_t cols) {
	if (rows < 2 || cols < 2) {
		return;
	}

	this->rows = rows;
	this->cols = cols;

	initMatrix(rows, cols);
}

Matrix::Matrix() {
	initMatrix(rows, cols);
}

Matrix::Matrix(const Matrix& other) {
	copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Matrix::~Matrix() {
	free();
}

Matrix& Matrix::operator+=(const Matrix& other) {
	if (rows == other.rows && cols == other.cols) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] += other.matrix[i][j];
			}
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
	if (rows == other.rows && cols == other.cols) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] -= other.matrix[i][j];
			}
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(int coefficient) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] *= coefficient;
		}
	}

	return *this;
}


Matrix& Matrix::operator++() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j]++;
		}
	}
}

Matrix Matrix::operator++(int dummy) {
	Matrix copyMatrix = *this;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j]++;
		}
	}

	return copyMatrix;
}

Matrix& Matrix::operator--() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j]--;
		}
	}
}

Matrix Matrix::operator--(int dummy) {
	Matrix copyMatrix = *this;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j]--;
		}
	}

	return copyMatrix;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.rows == rhs.rows && lhs.cols == rhs.cols) {
		Matrix resultMatrix(lhs.rows, lhs.cols);

		for (int i = 0; i < lhs.rows; i++) {
			for (int j = 0; j < lhs.cols; j++) {
				resultMatrix.matrix[i][j] = (lhs.matrix[i][j] + rhs.matrix[i][j]);
			}
		}

		return resultMatrix;
	}

	return {};
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.cols == rhs.rows) {
		Matrix resultMatrix(lhs.rows, lhs.cols);

		for (int i = 0; i < lhs.rows; i++) {
			for (int j = 0; j < rhs.cols; j++) {
				resultMatrix.matrix[i][j] = 0;

				for (int k = 0; k < rhs.rows; k++) {
					resultMatrix.matrix[i][j] += (lhs.matrix[i][k] + rhs.matrix[k][j]);
				}
			}
		}

		return resultMatrix;
	}

	return {};
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
		return false;
	}

	for (int i = 0; i < lhs.rows; i++) {
		for (int j = 0; j < lhs.cols; j++) {
			if (lhs.matrix[i][j] != rhs.matrix[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs) {
	return !(lhs == rhs);
}