#include <stdio.h>
#include <stdlib.h>

int* arange(int num, int start, int step);

int main()
{
	int num = 6, start = 2, step = 2;
	int* array = arange(num, start, step);

	for (int i = 0; i < num; i++)
	{
		printf("%d\n", array[i]);
	}
	return 0;
}

int* arange(int num, int start, int step)
{
	int* arr = calloc(num, sizeof(int));
	for (int i=0; i < num; i++)
	{
		arr[i] = start + i * step;
	}
	return arr;
}