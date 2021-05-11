#pragma once
#include<utility>

class Matrix {
private:
	std::pair<unsigned int, unsigned int> dimensions;
	float *data;
	unsigned int calculateIndex(unsigned int row, unsigned int column) const;
public:
	Matrix() = delete;
	Matrix(std::pair<unsigned int, unsigned int> dimensions);
	Matrix(unsigned int rows, unsigned int columns);
    ~Matrix();
};