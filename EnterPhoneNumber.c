#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Remove(char* string, char ch);

int main(void)
{
	char string[100], input[100];

	printf("Input phone number(include '-') : ");
	gets(input);

	strcpy(string, input);
	Remove(string, '-');
	printf("\nResult : %s\n", string);

	return 0;
}

void Remove(char* string, char ch)
{
	char* pstr = string;
	char* pstr0ld = strdup(string);
	char* pstrNew;
	char* pstr0ldFree = pstr0ld;

	pstrNew = strchr(pstr0ld, ch);

	while (pstrNew)
	{
		strncpy(pstr, pstr0ld, (pstrNew - pstr0ld));
		*(pstr + (pstrNew - pstr0ld)) = 0;

		pstr += (pstrNew - pstr0ld);

		pstr0ld = pstrNew + 1;
		pstrNew = strchr(pstr0ld, ch);

		if (pstrNew == NULL) {
			strcat(pstr, pstr0ld);
		}
	}
	free(pstr0ldFree);
}