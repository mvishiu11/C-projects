#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(int n, double* arr);
void read_array(int n, double* arr);
double l2_norm(int n, double* arr);
void swap(double *x, double *y);

int main()
{
	int n;
	printf("Enter array size: ");
	scanf("%d", &n);
	double A[32], B[32], C[32];
	read_array(n, A), read_array(n, B), read_array(n, C);
	print_array(n, A);
	printf("vector L2-norm = %lf\n", l2_norm(n, A));

	double* Z[3] = { A, B, C };
	for (int i = 0; i < 3; i++)
	{
		print_array(n, Z[i]);
		printf("%lf\n", l2_norm(n, Z[i]));
	}

	int sorted = 0;
	while (1)
	{
		sorted = 0;
		for (int i = 1; i < 3; i++)
		{
			if (l2_norm(n, Z[i]) > l2_norm(n, Z[i - 1]))
			{
				sorted += 1;
				for (int k = 0; k < n; k++)
				{
					swap(&Z[i][k], &Z[i - 1][k]);
				}
			}
		}
		if (sorted == 0)
		{
			break;
		}
	}

	printf("After sorting:\n");
	for (int i = 0; i < 3; i++)
	{
		print_array(n, Z[i]);
		printf("%lf\n", l2_norm(n, Z[i]));
	}

	int symmetric = 1;
	for (int i = 0; i < 3; i++)
	{
		if (n != 3)
		{
			printf("Not symmetric\n");
		}
		for (int j = 0; i < n; i++)
		{
			if (Z[i][j] != Z[j][i])
			{
				printf("Not symmetric\n");
				symmetric = 0;
				break;
			}
		}
	}

	if (symmetric == 1)
	{
		printf("Symmetric");
	}
	return 0;
}

void read_array(int n, double* arr)
{
	printf("\nEnter %d values: ", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &arr[i]);
	}
}

void print_array(int n, double* arr)
{
	printf("Values: ");
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", arr[i]);
	}
	printf("\t");
}

double l2_norm(int n, double* arr)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i] * arr[i];
	}
	return sqrt(sum);
}

void swap(double *x, double *y)
{
	double tmp = *x;
	*x = *y;
	*y = tmp;
}