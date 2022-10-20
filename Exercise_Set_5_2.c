#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
	char first_name[10];
	char last_name[20];
	int semester;
}student;

int compare(student* s1, student* s2);

void swap_students(student* s1, student* s2);

//void sort_students(student* list);

void print_student(student* s);

int main(void)
{
	student list[5] =
	{
		{"J","I",5},
		{"H","G",4},
		{"F","E",3},
		{"D","C",2},
		{"B","A",1},
	};
	
	for (int i = 0; i < 4; i++)
	{
		int j = i;
		while (j >= 0 && (compare(&list[j], &list[j + 1]) > 0))
		{
			swap_students(&list[j], &list[j + 1]);
			j--;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		print_student(&list[i]);
	}
}

int compare(student* s1, student* s2)
{
	if (strcmp(s1->last_name, s2->last_name) == 0)
	{
		if (strcmp(s1->first_name, s2->first_name) == 0)
		{
			if (s1->semester > s2->semester) return 1;
			if (s1->semester < s2->semester) return -1;
			return 0;
		}
		return strcmp(s1->first_name, s2->first_name);
	}
	return strcmp(s1->last_name, s2->last_name);
}

void swap_students(student* s1, student* s2)
{
	char temp_first[10], temp_last[20];
	int temp_sem;
	strcpy(temp_first, s2->first_name);
	strcpy(temp_last, s2->last_name);
	temp_sem = s2->semester;
	strcpy(s2->first_name, s1->first_name);
	strcpy(s2->last_name, s1->last_name);
	s2->semester = s1->semester;
	struct_strcpy(s1->first_name, temp_first);
	struct_strcpy(s1->last_name, temp_last);
	s1->semester = temp_sem;
}

//void sort_students(student* list)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int j = i;
//		while (j >= 0 && (compare(&list[j], &list[j + 1]) > 0))
//		{
//			swap_students(&list[j], &list[j + 1]);
//			j--;
//		}
//	}
//}

void print_student(student* s)
{
	printf("~~~~~\nFirst name : %s\nLast name: %s\nSemester: %d\n", s->first_name, s->last_name, s->semester);
}