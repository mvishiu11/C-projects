#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	unsigned int m;
	unsigned int cm;
}length;

int compare(length l1, length l2);
length add(length l1, length l2);
length substract(length l1, length l2);
void print(length);

int main(void)
{
	length l1={1,85}, l2={1,75}, sum, diff;
	sum = add(l1, l2);
	diff = substract(l1, l2);
	print(l1);
	print(l2);
	print(sum);
	print(diff);
}

int compare(length l1, length l2)
{
	if (l1.m == l2.m)
	{
		if (l1.cm == l2.cm) return 0;
		if (l1.cm > l2.cm) return 1;
		return -1;
	}
	if (l1.m > l2.m) return 1;
	return -1;
}

length add(length l1, length l2)
{
	length sum;
	sum.m = l1.m + l2.m;
	if (l1.cm + l2.cm > 99)
	{
		sum.cm = l1.cm + l2.cm - 100;
		sum.m++;
	}
	else sum.cm = l1.cm + l2.cm;
	return sum;
}

length substract(length l1, length l2)
{
	length diff={0,0};
	if (compare(l1, l2) == -1) return diff;
	if (l1.cm < l2.cm)
	{
		diff.cm = l1.cm + 100 - l2.cm;
		l1.m--;
	}
	else diff.cm = l1.cm - l2.cm;
	diff.m = l1.m - l2.m;
	return diff;
}

void print(length l)
{
	printf("%d m i %d cm\n", l.m, l.cm);
}