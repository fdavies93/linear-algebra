#include "stdafx.h"
#include "vector3.h"
#include <math.h>

vector3::vector3(double newX, double newY, double newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

vector3::vector3(const vector3& toCopy)
{
	x = toCopy.x;
	y = toCopy.y;
	z = toCopy.z;
}

vector3 vector3::operator+(const vector3& toAdd) const
{
	vector3 result(x + toAdd.x, y + toAdd.y, z + toAdd.z);
	return result;
}
vector3 vector3::operator-(const vector3& toSubtract) const
{
	vector3 result(x - toSubtract.x, y - toSubtract.y, z - toSubtract.z);
	return result;
}

vector3 vector3::operator*(const double& scalar) const
{
	vector3 result(x * scalar, y * scalar, z * scalar);
	return result;
}

void vector3::operator=(const vector3& toCopy)
{
	x = toCopy.x;
	y = toCopy.y;
	z = toCopy.z;
}

void vector3::operator=(const double values[3])
{
	x = values[0];
	y = values[1];
	z = values[2];
}

double vector3::dotProduct(const vector3& toDot) const
{
	double result = (x * toDot.x) + (y * toDot.y) + (z * toDot.z);
	return result;
}

vector3 vector3::crossProduct(const vector3& toCross) const
{
	vector3 result;
	result.x = (y * toCross.z) - (z * toCross.y);
	result.y = (z * toCross.x) - (x * toCross.z);
	result.y = (x * toCross.y) - (y * toCross.x);
	return result;
}

matrix vector3::toColumnMatrix() const
{
	matrix result;
	result.addRow({ x, y, z });
	result = result.transpose();
	return result;
}

vector3 vector3::rotateByEuler(const double& xR, const double& yR, const double& zR) const
{
	matrix calcMatrix = toColumnMatrix();
	matrix rotMatrix;
	rotMatrix = { {1, 0, 0}, {0, cos(xR), sin(xR)}, {0, -sin(xR), cos(xR) } };//x matrix
	calcMatrix = rotMatrix * calcMatrix;
	rotMatrix = { {cos(yR), 0, -sin(yR)}, {0, 1, 0}, {sin(yR),0,cos(yR)} }; //y matrix
	calcMatrix = rotMatrix * calcMatrix;
	rotMatrix = { {cos(zR), sin(zR), 0}, {-sin(zR), cos(zR), 0}, {0,0,1} };//z matrix
	calcMatrix = rotMatrix * calcMatrix;
	vector3 result(calcMatrix[0][0], calcMatrix[1][0], calcMatrix[2][0]);
	return result;
}

vector3 vector3::toUnitVector() const
{
	vector3 result;
	double scaleFactor;
	scaleFactor = 1 / (x + y + z);
	result.x = x * scaleFactor;
	result.y = y * scaleFactor;
	result.z = z * scaleFactor;
	return result;
}