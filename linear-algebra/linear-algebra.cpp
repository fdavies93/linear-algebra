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
	v1 = { 1.0, 0.0, 0.0 };
	v1 = v1.rotateByEuler(0, M_PI, 0);
	m3 = v1.toColumnMatrix();
	for (unsigned int i = 0; i < m3.rows(); ++i)
	{
		for (unsigned int i2 = 0; i2 < m3.columns(); ++i2) printf("%f ", m3[i][i2]);
		printf("\n");
	}
	system("PAUSE");
    return 0;
}

