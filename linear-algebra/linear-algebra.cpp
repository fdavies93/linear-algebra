// linear-algebra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "matrix.h"
#include <iostream>

//TESTS

int main()
{
	matrix m1, m2, m3;
	//m1 = { {1.0, 2.0, 3.0}, 
	//	   {4.0, 5.0, 6.0} };
	m2 = { {7.0, 8.0},
		   {9.0, 10.0}, 
		   {11.0, 12.0} };
	//m1 = { {1,0},{0,1} };
	//m2 = { {22}, {5} };
	m1 = m2.identity();
	m3 = m1 * m2;
	for (unsigned int i = 0; i < m3.rows(); ++i)
	{
		for (unsigned int i2 = 0; i2 < m3.columns(); ++i2) printf("%f ", m3[i][i2]);
		printf("\n");
	}
	system("PAUSE");
    return 0;
}

