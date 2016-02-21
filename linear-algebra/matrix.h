#pragma once
#include <vector>
#include <initializer_list>

class matrix {
private:
	std::vector<std::vector<double>> data;
	void copy(const matrix&);
public:
	//generic constructor
	matrix();
	//copy constructor
	matrix(const matrix&);
	//generates and returns identity matrix for this matrix
	matrix identity() const;
	//calculates and returns determinant
	double determinant() const;
	//calculates and returns transposed matrix
	matrix transpose() const;
	
    //used for throwing errors without breaking program (uncertain usefulness)
	static matrix empty();
	void addRow(const std::vector<double>&);
	matrix operator+(const matrix&) const;
	matrix operator-(const matrix&) const;
	matrix operator=(const matrix&);
	//allows matrix to be declared with initialiser list
	matrix operator=(std::initializer_list<std::vector<double>>);
	matrix operator*(const double) const;
	matrix operator*(const matrix&) const;
	void operator*=(const double);
	void operator*=(const matrix&);
	std::vector<double> operator[](unsigned int) const;
	unsigned int rows() const;
	unsigned int columns() const;
	void clear();
};