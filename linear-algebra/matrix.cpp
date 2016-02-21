#include "stdafx.h"
#include "matrix.h"
#include <cassert>

matrix matrix::empty()
{
	matrix empty;
	return empty;
}

void matrix::copy(const matrix& toCopy)
{
	for (unsigned int curRow = 0; curRow < toCopy.rows(); ++curRow)
	{
		data.push_back(toCopy[curRow]);
	}
}

matrix::matrix()
{

}

matrix::matrix(const matrix& toCopy)
{
	copy(toCopy);
}

void matrix::addRow(const std::vector<double>& toAdd)
{
	data.push_back(toAdd);
}

matrix matrix::operator+(const matrix& toAdd) const
{
	if (toAdd.rows() == rows() && toAdd.columns() == columns())
	{
		matrix result;
		std::vector<double> curRow;
		for (unsigned int rowI = 0; rowI < rows(); ++rowI)
		{
			curRow = toAdd[rowI];
			for (unsigned int colI = 0; colI < columns(); ++colI) curRow[colI] += data[rowI][colI];
			result.addRow(curRow);
		}
		return result;
	}
	else return empty();
}

matrix matrix::operator-(const matrix& toSubtract) const
{
	if (toSubtract.rows() == rows() && toSubtract.columns() == columns())
	{
		matrix result;
		std::vector<double> curRow;
		for (unsigned int rowI = 0; rowI < rows(); ++rowI)
		{
			curRow = toSubtract[rowI];
			for (unsigned int colI = 0; colI < columns(); ++colI) curRow[colI] -= data[rowI][colI];
			result.addRow(curRow);
		}
		return result;
	}
	else return empty();
}

matrix matrix::operator=(const matrix& toCopy)
{
	clear();
	copy(toCopy);
	return *this;
}

matrix matrix::operator=(std::initializer_list<std::vector<double>> it_list)
{
	clear();
	std::initializer_list<std::vector<double>>::iterator it;
	for (it = it_list.begin(); it != it_list.end(); ++it)
	{
		data.push_back(*it);
	}
	return *this;
}

std::vector<double> matrix::operator[](unsigned int row) const
{
	return data[row];
}

matrix matrix::operator*(const double scalar) const
{
	matrix result;
	std::vector<double> curRow;
	for (unsigned int rowI = 0; rowI < data.size(); ++rowI)
	{
		curRow = data[rowI];
		for (unsigned int colI = 0; colI < data[rowI].size(); ++colI) curRow[colI] *= scalar;
		result.addRow(curRow);
	}
	return result;
}

void matrix::operator*=(const double scalar)
{
	*this = *this * scalar;
}

matrix matrix::operator*(const matrix& toMultiply) const
{
	if (toMultiply.rows() == columns())
	{
		double cellTotal = 0;
		std::vector<double> curRow;
		matrix result;
		for (unsigned int rowI = 0; rowI < rows(); ++rowI)//row of result
		{
			curRow.clear();
			for (unsigned int colI = 0; colI < toMultiply.columns(); ++colI)//column of result
			{
				cellTotal = 0;
				for (unsigned int stepI = 0; stepI < columns(); ++stepI)
				{
					cellTotal += (data[rowI % rows()][stepI] * toMultiply[stepI][colI % toMultiply.columns()]);
				}
				curRow.push_back(cellTotal);
			}
			result.addRow(curRow);
		}
		return result;
	}
	else return empty();
}

void matrix::operator*=(const matrix& toMultiply)
{
	*this = *this * toMultiply;
}

matrix matrix::identity() const
{
	unsigned int size = rows();
	std::vector<double> curRow;
	matrix result;
	for (unsigned int rowI = 0; rowI < size; ++rowI)
	{
		curRow.clear();
		for (unsigned int colI = 0; colI < size; ++colI)
		{
			if (rowI == colI) curRow.push_back(1);
			else curRow.push_back(0);
		}
		result.addRow(curRow);
	}
	return result;
}

double matrix::determinant() const
{
	if (columns() == rows())
	{
		double result = 0;
		if (columns() == 2) // we can calculate it as a number!
		{
			result = (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]);
		}
		else //gotta generate more matrices
		{
			int sign = 1;
			matrix curMatrix;
			std::vector<double> curRow;
			for (unsigned int colI = 0; colI < columns(); ++colI)
			{
				curMatrix.clear();
				for (unsigned int row2I = 1; row2I < rows(); ++row2I)
				{
					curRow.clear();
					for (unsigned int col2I = 0; col2I < columns(); ++col2I)
					{
						if (col2I != colI) curRow.push_back(data[row2I][col2I]);
					}
					curMatrix.addRow(curRow);
				}
				result += (data[0][colI] * curMatrix.determinant() * sign);
				sign *= -1;
			}
		}
		return result;
	}
	else assert(false);
}

matrix matrix::transpose() const
{
	std::vector<double> curRow;
	matrix result;
	for (unsigned int colI = 0; colI < columns(); ++colI)
	{
		curRow.clear();
		for (unsigned int rowI = 0; rowI < rows(); ++rowI)
		{
			curRow.push_back(data[rowI][colI]);
		}
		result.addRow(curRow);
	}
	return result;
}

void matrix::clear()
{
	for (unsigned int i = 0; i < data.size(); ++i)
	{
		data[i].clear();
	}
	data.clear();
}

unsigned int matrix::rows() const
{
	return data.size();
}

unsigned int matrix::columns() const
{
	if (data.size() != 0) return data[0].size();
	else return 0;
}