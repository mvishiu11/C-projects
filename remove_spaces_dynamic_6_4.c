#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_spaces(char* str);

int main()
{
	char str[12] = "Hey sp ace ";
	char* another_str = remove_spaces(str);
	printf("%s", another_str);
	return 0;
}

char* remove_spaces(char* str)
{
	int len = (int) strlen(str), k = 0;
	char* new_str = calloc(1, sizeof(char));
	for (int i = 0; i<len; i++)
	{
		if (str[i] != ' ')
		{
			new_str[k] = str[i];
			k++;
			char* tmp = realloc(new_str, (k + 1) * sizeof(char));
			if (tmp != NULL)
				new_str = tmp;
		}
		new_str[k] = '\0';
	}
	return new_str;
}