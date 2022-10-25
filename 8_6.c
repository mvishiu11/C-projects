#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void replace(const char *file_name);

int main(void)
{
	replace("input.txt");
}

void replace(const char* file_name)
{
	FILE* file = fopen(file_name,"r+");
	if (!file)
	{
		perror("Error!\n");
		return;
	}
	int c = fgetc(file);
	while (c != EOF)
	{
		if ((c > 32 && c < 48) || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)
		{
			c = fgetc(file);
			fseek(file, -2, SEEK_CUR);
			fputc('_', file);
			fseek(file, 1, SEEK_CUR);
			
		}
		else c = fgetc(file);
	}
}
