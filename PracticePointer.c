#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(char *w);
void output(char *w);
void word(char *w);

int main()
{
	char w[100];

	input(w);
	word(w);
	output(w);

	return 0;
}

void input(char *w)
{
	printf("uppercase = ? ");
	scanf("%s", w);
}

void output(char *w)
{
	printf("lower case = %s\n", w);
}

void word(char *w)
{
	int i = 0;

	while (1) {
		if (*(w + i) == '\0') break;
		if (*(w + i) >= 'A' && *(w + i) <= 'Z') {
			*(w + i) = *(w + i) + 32;
		}
		else if (*(w + i) >= 'a' && *(w + i) <= 'z') {
			*(w + i) = *(w + i) - 32;
		}
		i++;
	}
}