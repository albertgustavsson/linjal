#pragma once
#include<utility>
#include<iostream>

class Matrix {
private:
	std::pair<unsigned int, unsigned int> dimensions;
	float *data;
	unsigned int calculateIndex(unsigned int row, unsigned int column) const;
public:
	Matrix() = delete;
	Matrix(std::pair<unsigned int, unsigned int> dimensions);
	Matrix(std::pair<unsigned int, unsigned int> dimensions, float value);
	Matrix(unsigned int rows, unsigned int columns);
	Matrix(unsigned int rows, unsigned int columns, float value);
    Matrix(const Matrix& other);
	Matrix(Matrix&& other);
    ~Matrix();
	std::pair<unsigned int, unsigned int> getDimensions() const;
	Matrix getInverse() const;
    Matrix& operator=(const Matrix& other);
	Matrix& operator=(Matrix&& other);
    float& operator()(unsigned int row, unsigned int column);
    float operator()(unsigned int row, unsigned int column) const;
    Matrix operator*(float scalar) const;
	Matrix& operator*=(float scalar);
	Matrix operator*(Matrix& other) const;
	Matrix operator+(Matrix& other) const;
};

std::ostream& operator<<(std::ostream& os, const Matrix& m);