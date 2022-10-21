#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	double Im, Re;
} CMPLX;

typedef struct {
	int n;
	CMPLX *set;
} CMPLX_SET;

void printCMPLX(CMPLX number);
void print_random_set(CMPLX_SET cmplxset);
void create_random_set(CMPLX_SET* pcs, int num);
void delete_random_set(CMPLX_SET* pcs);
void change_set_size(CMPLX_SET* pcs, int num);

int main()
{
	CMPLX_SET set;
	create_random_set(&set, 3);
	print_random_set(set);
	delete_random_set(&set);
	create_random_set(&set, 5);
	printf("\n");
	print_random_set(set);
	printf("\n");
	change_set_size(&set, 6);
	set.set[5].Re = 4;
	set.set[5].Im = 5;
	print_random_set(set);
	return 0;
}

void printCMPLX(CMPLX number)
{
	printf("%lf + %lfi\n", number.Re, number.Im);
}

void print_random_set(CMPLX_SET cmplxset)
{
	int n = cmplxset.n;
	for (int i = 0; i < n; i++)
	{
		printCMPLX(cmplxset.set[i]);
	}
}

void create_random_set(CMPLX_SET* pcs, int num)
{
	pcs->n = num;
	pcs->set = (CMPLX*)calloc(pcs->n, sizeof(CMPLX));
	srand((unsigned int)time(NULL));
	for (int i = 0; i < num; i++)
	{
		pcs->set[i].Re = rand();
		pcs->set[i].Im = rand();
	}
}

void delete_random_set(CMPLX_SET* pcs)
{
	free(pcs->set);
}

void change_set_size(CMPLX_SET* pcs, int num)
{
	CMPLX *tmp = (CMPLX*)realloc(pcs->set, num * sizeof(CMPLX));
	if (tmp != NULL)
		tmp = pcs->set;
	pcs->n += 1;
}
