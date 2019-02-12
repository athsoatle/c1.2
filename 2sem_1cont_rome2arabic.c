#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"

char * inputString(FILE * f, size_t size) {
	char * str;
	int ch;
	size_t len = 0;
	str = realloc(NULL, sizeof(char) * size);
	if (!str) {
		return str;
	}
	while (EOF != (ch = fgetc(f)) && ch != '\n') {
		str[len++] = ch;
		if (len == size) {
			str = realloc(str, sizeof(char)*(size += 16));
			if (!str)return str;
		}
	}
	str[len++] = '\0';

	return realloc(str, sizeof(char)*len);
}

static int romanDict(char c) {
	switch (c) {
		case 'M': return 1000;
		case 'D': return 500;
		case 'C': return 100;
		case 'L': return 50;
		case 'X': return 10;
		case 'V': return 5;
		case 'I': return 1;
	}
	return 0;
}

int romanToArab(char * s) {
	int ans = 0;
	int lastValue = 1001;
	for (char c = * s; c != 0; c = * (++s)) {//ИНКЕРМЕНТ ДОЛЖЕН БЫТЬ НАПИСАН ИМЕННО ТАК, ЧТОБЫ ПРОГРАММА РАБОТАЛА
		int value = romanDict(c);
		if (value > lastValue) {
			ans += (value - 2 * lastValue);
		}
		else {
			ans += value;
		}
		lastValue = value;
	}
	return ans;
}

int main() {
	char * romanIn = inputString(stdin, 10);
	int ans = romanToArab(romanIn);
	printf("%i\n", ans);
	free(romanIn);
	return 0;
}
