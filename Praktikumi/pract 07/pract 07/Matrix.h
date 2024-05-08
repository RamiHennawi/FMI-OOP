#pragma once

class Matrix {
private:
	int** matrix = nullptr;
	size_t rows = 2;
	size_t cols = 2;

	void initMatrix(size_t rows, size_t cols);
	void copyFrom(const Matrix& other);
	void free();

public:
	Matrix(size_t rows, size_t cols);

	Matrix();
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(int coefficient);

	Matrix& operator++();
	Matrix operator++(int dummy);
	Matrix& operator--();
	Matrix operator--(int dummy);

	friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
	friend bool operator==(const Matrix& lhs, const Matrix& rhs);
	friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
};
