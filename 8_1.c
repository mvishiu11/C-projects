#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int number_of_lines(const char* file_name);
int number_of_lines2(const char* file_name);

int main(void)
{
	printf("%d",number_of_lines2("8_1.txt"));
	return 0;
}

int number_of_lines(const char* file_name)
{
	FILE* file=fopen(file_name,"w");
	if(!file)
	{
		fprintf(stderr, "Error!\n");
		return EXIT_FAILURE;
	}
	int previous = getchar(), c, number = 0;
	if (previous == '\n') 
	{
		fclose(file);
		return number;
	}
	number++;
	fputc(previous, file);
	while (1)
	{
		c = getchar();
		if (c == '\n' && previous == '\n')
		{
			fclose(file);
			return number;
		}
		if (previous == '\n') fputc('\n',file);
		if(c!='\n') 
		{
			fputc(c, file);
			number++;
		}
		previous = c;
	}
}

int number_of_lines2(const char* file_name)
{
	FILE* file = fopen(file_name, "wx");
	if (!file)
	{
		fprintf(stderr, "File already exists!\n");
		return EXIT_FAILURE;
	}
	int previous = getchar(), c, number = 0;
	if (previous == '\n')
	{
		fclose(file);
		return number;
	}
	number++;
	fputc(previous, file);
	while (1)
	{
		c = getchar();
		if (c == '\n' && previous == '\n')
		{
			fclose(file);
			return number;
		}
		if (previous == '\n') fputc('\n', file);
		if (c != '\n')
		{
			fputc(c, file);
			number++;
		}
		previous = c;
	}
}
