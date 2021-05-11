#include "Matrix.h"

Matrix::Matrix(std::pair<unsigned int, unsigned int> dimensions) {
	this->dimensions = dimensions;
	data = new float[dimensions.first * dimensions.second];
}

Matrix::Matrix(unsigned int rows, unsigned int columns)
	: Matrix(std::make_pair(rows, columns)) {}

Matrix::Matrix(const Matrix& other) {
	dimensions = other.dimensions;
	data = new float[dimensions.first * dimensions.second];
	std::memcpy(data, other.data, dimensions.first * dimensions.second * sizeof(float));
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

Matrix& Matrix::operator=(const Matrix& other) {
	if (this == &other) return *this;
	delete[] data;
	dimensions = other.dimensions;
	data = new float[dimensions.first * dimensions.second];
	std::memcpy(data, other.data, dimensions.first * dimensions.second * sizeof(float));
	return *this;
}

float& Matrix::operator()(unsigned int row, unsigned int column) {
	return data[calculateIndex(row, column)];
}

float Matrix::operator()(unsigned int row, unsigned int column) const {
	return data[calculateIndex(row, column)];
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