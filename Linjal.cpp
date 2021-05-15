#include "Linjal.h"

Matrix::Matrix(std::pair<unsigned int, unsigned int> dimensions) {
	this->dimensions = dimensions;
	data = new float[dimensions.first * dimensions.second];
}

Matrix::Matrix(std::pair<unsigned int, unsigned int> dimensions, float value)
	: Matrix(dimensions) {
	for (unsigned int row = 0; row < dimensions.first; row++) {
		for (unsigned int column = 0; column < dimensions.second; column++) {
			operator()(row, column) = value;
		}
	}
}

Matrix::Matrix(unsigned int rows, unsigned int columns)
	: Matrix(std::make_pair(rows, columns)) {}

Matrix::Matrix(unsigned int rows, unsigned int columns, float value)
	: Matrix(std::make_pair(rows, columns), value) {}

Matrix::Matrix(const Matrix& other) {
	dimensions = other.dimensions;
	data = new float[dimensions.first * dimensions.second];
	std::memcpy(data, other.data, dimensions.first * dimensions.second * sizeof(float));
}

Matrix::Matrix(Matrix&& other) {
	dimensions = other.dimensions;
	data = other.data;
	other.dimensions = std::make_pair(0, 0);
	other.data = nullptr;
}

Matrix::~Matrix() {
	delete[] data;
}

unsigned int Matrix::calculateIndex(unsigned int row, unsigned int column) const {
	return row * dimensions.second + column;
}

std::pair<unsigned int, unsigned int> Matrix::getDimensions() const {
	return dimensions;
}

Matrix Matrix::getTranspose() const {
	Matrix result(dimensions.second, dimensions.first);
	for (unsigned int row = 0; row < dimensions.first; row++) {
		for (unsigned int column = 0; column < dimensions.second; column++) {
			result(column, row) = operator()(row, column);
		}
	}
	return result;
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this == &other) return *this;
	delete[] data;
	dimensions = other.dimensions;
	data = new float[dimensions.first * dimensions.second];
	std::memcpy(data, other.data, dimensions.first * dimensions.second * sizeof(float));
	return *this;
}

Matrix& Matrix::operator=(Matrix&& other) {
	if (this == &other) return *this;
	delete[] data;
	dimensions = other.dimensions;
	data = other.data;
	other.dimensions = std::make_pair(0, 0);
	other.data = nullptr;
	return *this;
}

float& Matrix::operator()(unsigned int row, unsigned int column) {
	return data[calculateIndex(row, column)];
}

float Matrix::operator()(unsigned int row, unsigned int column) const {
	return data[calculateIndex(row, column)];
}

Matrix Matrix::operator*(float scalar) const {
	Matrix result = *this;
	for (unsigned int row = 0; row < dimensions.first; row++) {
		for (unsigned int column = 0; column < dimensions.second; column++) {
			result(row, column) *= scalar;
		}
	}
	return result;
}

Matrix& Matrix::operator*=(float scalar) {
	*this = (*this)*scalar;
	return *this;
}

Matrix Matrix::operator*(Matrix& other) const {
	if (dimensions.second != other.dimensions.first) {
		// Error: bad dimensions of operands
	}

	Matrix result(dimensions.first, other.dimensions.second);
	for (unsigned int row = 0; row < result.dimensions.first; row++) {
		for (unsigned int column = 0; column < result.dimensions.second; column++) {
			result(row, column) = 0.0;
			for (unsigned int i = 0; i < dimensions.second; i++) {
				result(row, column) += operator()(row, i) * other(i, column);
			}
		}
	}
	return result;
}

Matrix Matrix::operator+(Matrix& other) const {
	if (dimensions != other.dimensions) {
		// Error: bad dimensions of operands
	}

	Matrix result(dimensions);
	for (unsigned int row = 0; row < dimensions.first; row++) {
		for (unsigned int column = 0; column < dimensions.second; column++) {
			result(row, column) = operator()(row, column) + other(row, column);
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	std::pair<unsigned int, unsigned int> dimensions = m.getDimensions();
	os << dimensions.first << " by " << dimensions.second << " matrix" << std::endl;
	for (unsigned int row = 0; row < dimensions.first; row++) {
		for (unsigned int column = 0; column < dimensions.second; column++)
			os << m(row, column) << " ";
		if (row != dimensions.first - 1)
			os << std::endl;
	}
	return os;
}