#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int m;
	int cm;
} length;

int main()
{
	int n;
	double element, sum=0;
	printf("Enter size of the array: ");
	scanf("%d", &n);
	double *doubles = calloc(n, sizeof(double));
	
	for (int i = 0; i < n; i++)
	{
		printf("Enter %d element: ", i+1);

		if (scanf("%lf", &element) != 1)
		{
			printf("Invalid input!");
			exit(EXIT_FAILURE);
		}
		doubles[i] = element;
		sum += element;
	}

	printf("Sum of all elements in the array: %lf", sum);
}