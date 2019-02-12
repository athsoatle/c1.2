#define _CRT_SECURE_NO_WARNINGS
#define ROMAN_SIZE 7

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int main() {
	int a;
	char ans[9] = "000000000";
	int b[3];
	scanf("%i", &a);
	b[0] = (a - a % 100) / 100;
	b[1] = (a - 100 * (a / 100) - a % 10) / 10;
	b[2] = (a - 10 * (a / 10));
	int i = 0;
	for (i = 0; i < 3; i++) {
		switch (b[i]) {
		case 0:
			ans[i * 3] = '-';
			ans[i * 3 + 1] = '-';
			ans[i * 3 + 2] = '-';
			break;
		case 1:
			ans[i * 3] = '-';
			ans[i * 3 + 1] = '-';
			ans[i * 3 + 2] = 'x';
			break;
		case 2:
			ans[i * 3] = '-';
			ans[i * 3 + 1] = 'w';
			ans[i * 3 + 2] = '-';
			break;
		case 3:
			ans[i * 3] = '-';
			ans[i * 3 + 1] = 'w';
			ans[i * 3 + 2] = 'x';
			break;
		case 4:
			ans[i * 3] = 'r';
			ans[i * 3 + 1] = '-';
			ans[i * 3 + 2] = '-';
			break;
		case 5:
			ans[i * 3] = 'r';
			ans[i * 3 + 1] = '-';
			ans[i * 3 + 2] = 'x';
			break;
		case 6:
			ans[i * 3] = 'r';
			ans[i * 3 + 1] = 'w';
			ans[i * 3 + 2] = '-';
			break;
		case 7:
			ans[i * 3] = 'r';
			ans[i * 3 + 1] = 'w';
			ans[i * 3 + 2] = 'x';
			break;
		}
	}
	printf("%9.9s\n", ans);
	system("PAUSE");
	return 0;
}
