#pragma once
#include <initializer_list>
#include "matrix.h"

class vector3 {
public:
	double x, y, z;
	vector3(double newX = 0, double newY = 0, double newZ = 0);//quick constructor
	vector3(const vector3&);//copy constructor
	vector3 operator+(const vector3&) const;
	vector3 operator-(const vector3&) const;
	vector3 operator*(const double&) const;
	void operator=(const vector3&);
	void operator=(const double[3]);
	double dotProduct(const vector3&) const;
	vector3 crossProduct(const vector3&) const;
	matrix toColumnMatrix() const;
	vector3 rotateByEuler(const double&, const double&, const double&) const;
};