#pragma once
#include <vector>
#include <initializer_list>

class matrix {
private:
	std::vector<std::vector<double>> data;
	void copy(const matrix&);
public:
	//constructors
	matrix();
	matrix(const matrix&);
	//matrix identity();
	static matrix empty();
	void addRow(const std::vector<double>&);
	matrix operator+(const matrix&) const;
	matrix operator-(const matrix&) const;
	matrix operator=(const matrix&);
	matrix operator=(std::initializer_list<std::vector<double>>);
	matrix operator*(const double) const;
	matrix operator*(const matrix&) const;
	std::vector<double> operator[](unsigned int) const;
	unsigned int rows() const;
	unsigned int columns() const;
	void clear();
};