/*
 * main.c
 *
 *  Created on: Aug 25, 2016
 *      Author: lidq
 */

#include <stdio.h>
#include <matrix.h>
#include <time.h>

#define M 	(100)
#define N 	(3)

double y(double x)
{
	return 3.2 * pow(x, 0) + 7.6 * pow(x, 1) - 2.5 * pow(x, 2);
}

int main(int argc, char *argv[])
{
	s_Matrix X;
	s_Matrix Y;
	s_Matrix P;
	matrix_init(&X, M, N);
	matrix_init(&Y, M, 1);
	matrix_init(&P, N, 1);
	s_Matrix X_T;
	s_Matrix X_INV;
	s_Matrix X_temp;
	matrix_init(&X_T, N, M);
	matrix_init(&X_INV, N, N);
	matrix_init(&X_temp, N, N);

	srand((int) time(0));

	for (int i = 0, x = 0; i < M * N; i += N, x++)
	{
		for (int j = 0; j < N; j++)
		{
			X.v[i + j] = pow(x, j);
		}

		Y.v[x] = y(x);
	}

//	matrix_display(&X);
//	matrix_display(&Y);

	matrix_transposition(&X_T, &X);
	matrix_mult(&X_temp, &X_T, &X);
	matrix_inverse(&X_INV, &X_temp);
//	printf("inv:\n");
//	matrix_display(&X_INV);

	matrix_destory(&X_temp);
	matrix_init(&X_temp, M, N);

	matrix_mult(&X_temp, &X_INV, &X_T);
	matrix_mult(&P, &X_temp, &Y);
	printf("PARAMS:\n");
	matrix_display(&P);

	matrix_destory(&X_temp);
	matrix_destory(&X_INV);
	matrix_destory(&X_T);
	matrix_destory(&X);
	matrix_destory(&Y);
	matrix_destory(&P);

//	int S = 3;
//	s_Matrix A;
//	s_Matrix T;
//	matrix_init(&A, S, S);
//	matrix_init(&T, S, S);
//
//	A.v[0] = 1;
//	A.v[1] = -2;
//	A.v[2] = 1;
//
//	A.v[3] = 3;
//	A.v[4] = 2;
//	A.v[5] = -2;
//
//	A.v[6] = -2;
//	A.v[7] = 3;
//	A.v[8] = -2;
//
//
//	matrix_inverse(&T, &A);
//	matrix_display(&T);
//
//	matrix_destory(&A);
//	matrix_destory(&T);
//
//	printf("done.\n");

	return 0;
}

