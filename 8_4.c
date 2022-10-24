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
student* get_students(const char* file_name);
void print(student* students,int size);

int main(void)
{
	int size = 3;
	student students[3] = {
		{"A","B",1},
		{"C","D",2},
		{"E","F",3}
	};
	student* students2;
	print_students("8_4.txt", students, size);
	students2 = get_students("8_4.txt");
	print(students2,size);
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

student* get_students(const char* file_name)
{
	FILE* file = fopen(file_name, "r");
	if (!file)
	{
		perror("File does not exist!\n");
		return NULL;
	}
	int size;
	fscanf(file, "%d", &size);
	fseek(file, 1, SEEK_CUR);
	student* students = calloc(size, sizeof(student));
	for (int i = 0; i < size; i++)
	{
		fscanf(file, "%s", (students + i)->first_name);
		fseek(file, 1, SEEK_CUR);
		fscanf(file, "%s", (students + i)->last_name);
		fseek(file, 1, SEEK_CUR);
		fscanf(file, "%d", &(students + i)->semester);
		fseek(file, 1, SEEK_CUR);
	}
	return students;
}

void print(student* students,int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s %s %d\n", (students + i)->first_name, (students + i)->last_name, (students + i)->semester);
	}
}