#include <stdio.h>

void input(int* y);
int leapYear(int y);
int year(int y);
int month(int y, int m);
int lastDay(int y, int m);
int dayStart(int total);
void calendar(int total, int m, int l);
void yearCalendar(int y);

int main()
{
	int y;

	input(&y);
	yearCalendar(y);

    return 0;
}

void input(int* y)
{
	printf("yyyy : ");
	scanf("%d", y);
	printf("\n");
}

int leapYear(int y)
{
	if (y % 400 == 0 || y % 100 != 0 && y % 4 == 0) {
		return 1;
	}
	else
		return 0;
}

int year(int y)
{
	int k, sum = 0;

	for (k = 1; k < y; k++) {
		sum += 365 + leapYear(k);
	}
	return sum;
}

int month(int y, int m)
{
	int t = 0;

	switch (m - 1) {
	case 12: t += 31;
	case 11: t += 30;
	case 10: t += 31;
	case 9: t += 30;
	case 8: t += 31;
	case 7: t += 31;
	case 6: t += 30;
	case 5: t += 31;
	case 4: t += 30;
	case 3: t += 31;
	case 2: t += 28 + leapYear(y);
	case 1: t += 31;
	}
	return t;
}

int lastDay(int y, int m)
{
	int t;

	switch (m) {
	case 12: t = 31; break;
	case 11: t = 30; break;
	case 10: t = 31; break;
	case 9: t = 30; break;
	case 8: t = 31; break;
	case 7: t = 31; break;
	case 6: t = 30; break;
	case 5: t = 31; break;
	case 4: t = 30; break;
	case 3: t = 31; break;
	case 2: t = 28 + leapYear(y); break;
	case 1: t = 31;
	}
	return t;
}

int dayStart(int total)
{
	int s;

	switch (total % 7) {
	case 0: s = 0; break;
	case 1: s = -1; break;
	case 2: s = -2; break;
	case 3: s = -3; break;
	case 4: s = -4; break;
	case 5: s = -5; break;
	case 6: s = -6; break;
	}
	return s;
}

void calendar(int total, int m, int l)
{
	int a, b, c = dayStart(total);

	printf("<Month: %d>\n", m);
	printf("SUN MON TUE WED THU FRI SAT\n");
	for (a = 1; a <= 6; a++) {
		for (b = 1; b <= 7; b++) {
			c++;
			if (c <= 0) {
				printf("    ");
			}
			else if (c <= l) {
				printf("%3d ", c);
			}
		}
		if (c <= l) {
			printf("\n");
		}
	}
	printf("\n\n");
}

void yearCalendar(int y)
{
	int total, l, m;
	total = year(y) + month(y, 1) + 1;
	for (m = 1; m <= 12; m++) {
		l = lastDay(y, m);
		calendar(total, m, l);
		total += l;
	}
}
