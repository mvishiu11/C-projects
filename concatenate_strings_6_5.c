#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cat_str(char* str, char* str2);

int main()
{
	char str[15] = "Hello ";
	char str2[6] = "you!";
	char* another_str = cat_str(str, str2);
	printf("%s", another_str);
	return 0;
}

char* cat_str(char* str, char* str2)
{
	char* big_str = calloc(strlen(str) + strlen(str2) + 1, sizeof(char));
	int max_len = (int)strlen(str) + (int)strlen(str2);
	for (int i = 0; i < (int)strlen(str); i++)
	{
			big_str[i] = str[i];
	}
	for (int i = (int)strlen(str); i < max_len; i++)
	{
		big_str[i] = str2[i-(int)strlen(str)];
	}
	return big_str;
}