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
	Matrix(Matrix&& other) noexcept;
    ~Matrix();
	std::pair<unsigned int, unsigned int> getDimensions() const;
	Matrix getTranspose() const;
    Matrix& operator=(const Matrix& other) noexcept;
	Matrix& operator=(Matrix&& other) noexcept;
    float& operator()(unsigned int row, unsigned int column);
    float operator()(unsigned int row, unsigned int column) const;
    Matrix operator*(float scalar) const;
	Matrix& operator*=(float scalar);
	Matrix operator*(Matrix& other) const;
	Matrix operator+(Matrix& other) const;
};

std::ostream& operator<<(std::ostream& os, const Matrix& m);

class Vector {
private:
	unsigned int dimensions;
	float* data;
public:
	Vector() = delete;
	Vector(unsigned int dimensions);
	Vector(unsigned int dimensions, float value);
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;
	~Vector();
	unsigned int getDimensions() const;
	Vector& operator=(const Vector& other) noexcept;
	Vector& operator=(Vector&& other) noexcept;
	float& operator()(unsigned int dimension);
	float operator()(unsigned int dimension) const;
	Vector operator*(float scalar) const;
	Vector& operator*=(float scalar);
	Vector operator+(Vector& other) const;
	Vector operator-() const;
	Vector operator-(Vector& other) const;
	float dotProduct(Vector& other) const;
};

std::ostream& operator<<(std::ostream& os, const Vector& v);