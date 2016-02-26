// linear-algebra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "matrix.h"
#include "vector3.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
//TESTS

int main()
{
	matrix m1, m2, m3;
	vector3 v1;
	m1 = { {12, 9, 1} , {8 , 5, 6} , {2 , -2 , 0} };
	m3 = m1.inverse();
	//m3 = m1 * m2;

	for (unsigned int i = 0; i < m3.rows(); ++i)
	{
		for (unsigned int i2 = 0; i2 < m3.columns(); ++i2) printf("%f ", m3[i][i2]);
		printf("\n");
	}
	system("PAUSE");
    return 0;
}

