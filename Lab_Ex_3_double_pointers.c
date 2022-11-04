#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function prototypes for readability
void print_array(int n, double* arr);
void read_array(int n, double* arr);
double l2_norm(int n, double* arr);
void swap_arrays(double** x, double** y);

int main()
{
	int n;
	printf("Enter array size: ");
	scanf("%d", &n);										//Get array size from the user
	double A[32], B[32], C[32];								//Set max size for arrays (dynamic allocation restricted for this lab)
	read_array(n, A), read_array(n, B), read_array(n, C);   //Read values from the user
	print_array(n, A);										//Print values of the first array
	printf("vector L2-norm = %lf\n", l2_norm(n, A));		//as well as its Euclidean norm

	double* Z[3] = { A, B, C };								//Declare array of pointers to double containing all three read arrays
	for (int i = 0; i < 3; i++)								
	{
		print_array(n, Z[i]);								//Print values of the arrays contained in Z
		printf("%lf\n", l2_norm(n, Z[i]));					//as well as their Euclidean norms
	}

	int sorted = 0;											//Declare a flag to check if array is sorted
	while (1)												//Repeat steps below until array Z is sorted
	{
		sorted = 0;											//1. Reset flag
		for (int i = 1; i < 3; i++)							//2. Iterate through array one time
		{
			if (l2_norm(n, Z[i]) > l2_norm(n, Z[i - 1]))	//3. For each iteration compare Euclidean norms of neigbouring arrays
			{												
				swap_arrays(&Z[i], &Z[i - 1]);				//4. Swap variables if comparison indicates the need
				sorted += 1;								//5. If variables were swapped, increment the flag
			}
		}
		if (sorted == 0)									//If no swaps were needed, then break the loop. Your array is sorted!
		{
			break;
		}
	}

	printf("After sorting:\n");								//Print out sorted array
	for (int i = 0; i < 3; i++)
	{
		print_array(n, Z[i]);
		printf("%lf\n", l2_norm(n, Z[i]));
	}

	int symmetric = 1;										//Declare a flag (in this case, assuming array is symmetric)
	for (int i = 0; i < 3; i++)
	{
		if (n != 3)											//If n is different than size of Z, then it cannot be symmetric, since we need a square
		{
			printf("Not symmetric\n");						
		}
		for (int j = 0; i < n; i++)
		{
			if (Z[i][j] != Z[j][i])							//Check whether the matrix is the same as its transpose (ergo is symmetric)
			{
				printf("Not symmetric\n");
				symmetric = 0;								//if not reset the flag
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

void swap_arrays(double** x, double** y)
{
	double* tmp = *x;
	*x = *y;
	*y = tmp;
}