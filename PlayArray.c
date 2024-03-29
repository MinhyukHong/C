#include <stdio.h>

int input();
void init(int data[3][3]);
void copyArray(int data[3][3], int datb[3][3]);
void rotateRight(int data[3][3]);
void rotateLeft(int data[3][3]);
void print(int data[3][3]);
void play();

int main()
{
	play();

	return 0;
}

int input()
{
	char c;

	printf("Input letter : ");
	scanf(" %c", &c);

	return c;
}

void init(int data[3][3])
{
	int i, j, k = 1;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			data[i][j] = k++;
		}
	}
}

void copyArray(int data[3][3], int datb[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			data[i][j] = datb[i][j];
		}
	}
}

void rotateRight(int data[3][3])
{
	int datb[3][3];
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			datb[i][2 - j] = data[j][i];
		}
	}
	copyArray(data, datb);
}

void rotateLeft(int data[3][3])
{
	int datb[3][3];
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			datb[2 - j][i] = data[i][j];
		}
	}
	copyArray(data, datb);
}

void print(int data[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%2d", data[i][j]);
		}
		printf("\n");
	}
}

void play()
{
	int data[3][3];
	char c;

	init(data);

	do {
		c = input();

		if (c == 'r') {
			rotateRight(data);
			print(data);
		}
		else if (c == 'l') {
			rotateLeft(data);
			print(data);
		}
		else if (c == 'q') {
			printf("The play has ended.\n"); break;
		}
		else
			printf("Please reenter\n");
			printf("\n");
	} while (1);
}