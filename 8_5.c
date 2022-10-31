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
void print(student* students, int size);

int main(void)
{
	int size = 3;
	student students[3] = {
		{"A","B",1},
		{"C","D",2},
		{"E","F",3}
	};
	student* students2;
	print_students("8_5.bin", students, size);
	students2 = get_students("8_5.bin");
	print(students2, size);
}

void print_students(const char* file_name, student* students, int size)
{
	FILE* file = fopen(file_name, "wb");
	if (!file)
	{
		perror("Error!\n");
		return;
	}
	fwrite(&size, sizeof(int), 1, file);
	fwrite(students, sizeof(student), size, file);
	fclose(file);
}

student* get_students(const char* file_name)
{
	FILE* file = fopen(file_name, "rb");
	if (!file)
	{
		perror("File does not exist!\n");
		return NULL;
	}
	int size;
	fread(&size,sizeof(int),1,file);
	student* students = calloc(size, sizeof(student));
	fread(students, sizeof(student), size, file);
	return students;
}

void print(student* students, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s %s %d\n", (students + i)->first_name, (students + i)->last_name, (students + i)->semester);
	}
}