#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_from_file(const char* file_name);

int main(void)
{
	print_from_file("input.txt");
	return 0;
}

void print_from_file(const char* file_name)
{
	FILE* file = fopen(file_name, "r");
	if (!file)
	{
		perror("Error!\n");
		return;
	}
	int c;
	while ((c = fgetc(file)) != EOF)
	{
		if ((c>32 && c<48) || (c > 90 && c < 97) || c>122) putchar('_');
		else putchar(c);
	}
	fclose(file);
}
