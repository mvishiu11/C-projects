#include <stdio.h>
#include <stdlib.h>

int* split_digits(int number);
void reverse_array(int* arr, int n);

int main()
{
	int n = 1234567;
	int* array = split_digits(n);
	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", array[i]);
	}
	return 0;
}

int* split_digits(int number)
{
	int* arr = NULL;
	int* tmp = calloc(2, sizeof(int));
	if (tmp != NULL)
	{
		arr = tmp;
	}
	int i = 0;
	while (number != 0)
	{
		arr[i] = number % 10;
		number /= 10;
		int* tmp2 = realloc(arr, (3 + i) * sizeof(int));
		if (tmp2 != NULL)
		{
			arr = tmp2;
			i++;
		}
	}
	reverse_array(arr, i);
	arr[i] = -1;
	return arr;
}

void reverse_array(int* arr, int n)
{
	int temp;
	for (int i = 0; i < n / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
}