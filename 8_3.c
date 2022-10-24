#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	char first_name[10];
	char last_name[20];
	int semester;
}student;

void print_students(const char* file_name, student* students, int size);

int main(void)
{
	int size = 3;
	student students[3] = {
		{"A","B",1},
		{"C","D",2},
		{"E","F",3}
	};

	print_students("8_3.txt",students,size);
}

void print_students(const char* file_name, student* students, int size)
{
	FILE* file = fopen(file_name, "w");
	if (!file)
	{
		perror("Error!\n");
		return;
	}
	fprintf(file, "%d\n", size);
	for (int i = 0; i < size; i++)
	{
		fprintf(file, "%s %s %d\n", (students + i)->first_name, (students + i)->last_name, (students + i)->semester);
	}
	fclose(file);
}