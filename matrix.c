/*
 * matrix.c
 *
 *  Created on: Aug 25, 2016
 *      Author: lidq
 */

#include <matrix.h>

//初始化矩阵
int matrix_init(s_Matrix *matrix, int m, int n)
{
	if (matrix == null)
	{
		return -1;
	}

	if (m <= 0 || n <= 0)
	{
		return -1;
	}

	//初始化矩阵大小
	matrix->m = m;
	matrix->n = n;

	//申请存放矩阵数据的内存空间
	matrix->v = malloc(sizeof(num) * matrix->m * matrix->n);
	if (matrix->v == null)
	{
		return -1;
	}

	//将矩阵中所有的元素置为0
	matrix_zero(matrix);

	return 0;
}

//销毁矩阵
int matrix_destory(s_Matrix *matrix)
{
	if (matrix == null)
	{
		return -1;
	}

	//释放矩阵元素占用的内存空间
	if (matrix->v != null)
	{
		free(matrix->v);
	}

	//清除矩阵大小
	matrix->m = 0;
	matrix->n = 0;

	return 0;
}

//置空矩阵
int matrix_zero(s_Matrix *matrix)
{
	if (matrix == null)
	{
		return -1;
	}

	if (matrix->v == null)
	{
		return -1;
	}

	if (matrix->m <= 0 || matrix->n <= 0)
	{
		return -1;
	}

	//将所有元素的值置为0
	for (int i = 0; i < matrix->m; i++)
	{
		for (int j = 0; j < matrix->n; j++)
		{
			matrix->v[i * matrix->n + j] = 0;
		}
	}

	return 0;
}

int matrix_add(s_Matrix *result, s_Matrix *src, s_Matrix *src1)
{
	if (result == null)
	{
		return -1;
	}

	if (result->v == null)
	{
		return -1;
	}

	if (src == null)
	{
		return -1;
	}

	if (src->v == null)
	{
		return -1;
	}

	if (src->m <= 0 || src->n <= 0)
	{
		return -1;
	}

	if (src1 == null)
	{
		return -1;
	}

	if (src1->v == null)
	{
		return -1;
	}

	if (src1->m <= 0 || src1->n <= 0)
	{
		return -1;
	}

	if (src->m != src1->m || src->n != src1->n)
	{
		return -1;
	}

	for (int i = 0; i < src->m; i++)
	{
		for (int j = 0; j < src->n; j++)
		{
			result->v[i * src->n + j] = src->v[i * src->n + j] + src1->v[i * src->n + j];
		}
	}

	result->m = src->m;
	result->n = src->n;

	return 0;
}

int matrix_add_num(s_Matrix *result, s_Matrix *src, num v)
{
	if (result == null)
	{
		return -1;
	}

	if (result->v == null)
	{
		return -1;
	}

	if (src == null)
	{
		return -1;
	}

	if (src->v == null)
	{
		return -1;
	}

	if (src->m <= 0 || src->n <= 0)
	{
		return -1;
	}

	for (int i = 0; i < src->m; i++)
	{
		for (int j = 0; j < src->n; j++)
		{
			result->v[i * src->n + j] = src->v[i * src->n + j] + v;
		}
	}

	result->m = src->m;
	result->n = src->n;

	return 0;
}

int matrix_add_num_slef(s_Matrix *self, num v)
{

	if (self == null)
	{
		return -1;
	}

	if (self->v == null)
	{
		return -1;
	}

	if (self->m <= 0 || self->n <= 0)
	{
		return -1;
	}

	for (int i = 0; i < self->m; i++)
	{
		for (int j = 0; j < self->n; j++)
		{
			self->v[i * self->n + j] += v;
		}
	}

	return 0;
}

int matrix_mult(s_Matrix *result, s_Matrix *src, s_Matrix *src1)
{
	if (result == null)
	{
		return -1;
	}

	if (result->v == null)
	{
		return -1;
	}

	if (src == null)
	{
		return -1;
	}

	if (src->v == null)
	{
		return -1;
	}

	if (src->m <= 0 || src->n <= 0)
	{
		return -1;
	}

	if (src1 == null)
	{
		return -1;
	}

	if (src1->v == null)
	{
		return -1;
	}

	if (src1->m <= 0 || src1->n <= 0)
	{
		return -1;
	}

	if (src->n != src1->m)
	{
		return -1;
	}

	result->m = src->m;
	result->n = src1->n;

	for (int i = 0; i < result->m; i++)
	{
		for (int j = 0; j < result->n; j++)
		{
			num v = 0;
			for (int k = 0; k < src->n; k++)
			{
				v += src->v[i * src->n + k] * src1->v[k * src1->n + j];
			}
			result->v[i * result->n + j] = v;
		}
	}

	return 0;
}

int matrix_transposition(s_Matrix *result, s_Matrix *src)
{
	if (result == null)
	{
		return -1;
	}

	if (result->v == null)
	{
		return -1;
	}

	if (src == null)
	{
		return -1;
	}

	if (src->v == null)
	{
		return -1;
	}

	if (src->m <= 0 || src->n <= 0)
	{
		return -1;
	}

	result->m = src->n;
	result->n = src->m;

	for (int i = 0; i < src->m; i++)
	{
		for (int j = 0; j < src->n; j++)
		{
			result->v[j * result->n + i] = src->v[i * src->n + j];
		}
	}

	return 0;
}

int matrix_mult_num(s_Matrix *result, s_Matrix *src, num v)
{
	if (result == null)
	{
		return -1;
	}

	if (result->v == null)
	{
		return -1;
	}

	if (src == null)
	{
		return -1;
	}

	if (src->v == null)
	{
		return -1;
	}

	if (src->m <= 0 || src->n <= 0)
	{
		return -1;
	}

	result->m = src->m;
	result->n = src->n;

	for (int i = 0; i < src->m; i++)
	{
		for (int j = 0; j < src->n; j++)
		{
			result->v[i * result->n + j] = src->v[i * src->n + j] * v;
		}
	}

	return 0;
}

int matrix_mult_num_self(s_Matrix *self, num v)
{
	if (self == null)
	{
		return -1;
	}

	if (self->v == null)
	{
		return -1;
	}

	if (self->m <= 0 || self->n <= 0)
	{
		return -1;
	}

	for (int i = 0; i < self->m; i++)
	{
		for (int j = 0; j < self->n; j++)
		{
			self->v[i * self->n + j] *= v;
		}
	}

	return 0;
}

int matrix_determinant(num *result, s_Matrix *src)
{
	if (src == null)
	{
		return -1;
	}

	if (src->v == null)
	{
		return -1;
	}

	if (src->m <= 0 || src->n <= 0)
	{
		return -1;
	}

	if (src->m != src->n)
	{
		return -1;
	}

	if (result == null)
	{
		return -1;
	}

	if (src->m == 1)
	{
		*result = src->v[0];
		return 0;
	}

	if (src->m == 2)
	{
		*result = src->v[0] * src->v[3] - src->v[1] * src->v[2];
		return 0;
	}

	num s = 0;
	for (int k = 0; k < src->m; k++)
	{
		num det = 0;
		s_Matrix cofactor;
		matrix_init(&cofactor, src->m - 1, src->n - 1);
		for (int i = 1, ci = 0; i < src->m; i++, ci++)
		{
			for (int j = 0, cj = 0; j < src->n; j++)
			{
				if (j != k)
				{
					cofactor.v[ci * cofactor.n + cj] = src->v[i * src->n + j];
					cj++;
				}
			}
		}
		matrix_determinant(&det, &cofactor);
		matrix_destory(&cofactor);
		s += src->v[k] * pow(-1, 0 + k) * det;
	}

	*result = s;

	return 0;
}

int matrix_adjoint(s_Matrix *result, s_Matrix *src)
{
	if (result == null)
	{
		return -1;
	}

	if (result->v == null)
	{
		return -1;
	}

	if (result->m <= 0 || result->n <= 0)
	{
		return -1;
	}

	if (src == null)
	{
		return -1;
	}

	if (src->v == null)
	{
		return -1;
	}

	if (src->m <= 0 || src->n <= 0)
	{
		return -1;
	}

	if (src->m != src->n)
	{
		return -1;
	}

	result->m = src->m;
	result->n = src->n;

	if (src->m == 1)
	{
		result->v[0] = 1;
		return 0;
	}

	int cm = src->m - 1;
	int cn = src->n - 1;

	s_Matrix cofactor;
	matrix_init(&cofactor, cm, cn);

	for (int i = 0; i < src->m; i++)
	{
		for (int j = 0; j < src->n; j++)
		{
			for (int k = 0, ck = 0; k < src->m; k++)
			{
				if (k != i)
				{
					for (int l = 0, cl = 0; l < src->n; l++)
					{
						if (l != j)
						{
							cofactor.v[ck * cofactor.n + cl] = src->v[k * src->n + l];
							cl++;
						}
					}
					ck++;
				}
			}
			num det = 0;
			matrix_determinant(&det, &cofactor);
			result->v[j * result->n + i] = pow(-1, i + j) * det;
		}
	}

	matrix_destory(&cofactor);

	return 0;
}

int matrix_inv(s_Matrix *result, s_Matrix *src)
{
	if (result == null)
	{
		return -1;
	}

	if (result->v == null)
	{
		return -1;
	}

	if (result->m <= 0 || result->n <= 0)
	{
		return -1;
	}

	if (src == null)
	{
		return -1;
	}

	if (src->v == null)
	{
		return -1;
	}

	if (src->m <= 0 || src->n <= 0)
	{
		return -1;
	}

	if (src->m != src->n)
	{
		return -1;
	}

	num det = 0;
	matrix_determinant(&det, src);
	if (det == 0)
	{
		return -1;
	}

	s_Matrix adjoint;
	matrix_init(&adjoint, src->m, src->n);
	matrix_adjoint(&adjoint, src);
	matrix_mult_num(result, &adjoint, 1.0 / det);

	matrix_destory(&adjoint);

	return 0;
}

int matrix_inverse(s_Matrix *result, s_Matrix *src)
{
	if (src == null)
	{
		return -1;
	}

	if (src->v == null)
	{
		return -1;
	}

	if (src->m <= 0 || src->n <= 0)
	{
		return -1;
	}

	if (src->m != src->n)
	{
		return -1;
	}

	if (result == null)
	{
		return -1;
	}

	if (result->v == null)
	{
		return -1;
	}

	if (result->m <= 0 || result->n <= 0)
	{
		return -1;
	}

	if (result->m != src->n)
	{
		return -1;
	}

	if (src->m == 1)
	{
		result->v[0] = 1.0 / src->v[0];
		return 0;
	}

	int err = 0;
	int n = src->m;
	s_Matrix temp;
	matrix_init(&temp, n, n * 2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp.v[i * (n * 2) + j] = src->v[i * n + j];
		}
		temp.v[i * (n * 2) + (i + n)] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int row = 0; row < n; row++)
		{
			if (row != i)
			{
				if (temp.v[i * (n * 2) + i] == 0)
				{
					err = 1;
					goto _label_inf;
				}
				num a = -temp.v[row * (n * 2) + i] / temp.v[i * (n * 2) + i];

				for (int j = i; j < (n * 2); j++)
				{
					temp.v[row * (n * 2) + j] += temp.v[i * (n * 2) + j] * a;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		num a = temp.v[i * (n * 2) + i];
		if (a == 0)
		{
			err = 1;
			goto _label_inf;
		}
		for (int j = i; j < (n * 2); j++)
		{
			temp.v[i * (n * 2) + j] /= a;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result->v[i * n + j] = temp.v[i * (n * 2) + (j + n)];
		}
	}

	_label_inf: ;
	matrix_destory(&temp);

	if (err)
	{
		return matrix_inv(result, src);
	}

	return 0;
}

//显示矩阵内容
int matrix_display(s_Matrix *matrix)
{
	if (matrix == null)
	{
		return -1;
	}

	if (matrix->v == null)
	{
		return -1;
	}

	if (matrix->m <= 0 || matrix->n <= 0)
	{
		return -1;
	}

	//显示所有元素值
	for (int i = 0; i < matrix->m; i++)
	{
		for (int j = 0; j < matrix->n; j++)
		{
			printf("%+e\t\t", matrix->v[i * matrix->n + j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
