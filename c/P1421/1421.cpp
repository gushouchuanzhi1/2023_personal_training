#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)£»
#define PRICE 19

int main() {
	int a, b;
	int num = 0;
	scanf("%d %d", &a, &b);
	int money = a * 10 + b;
	num = money / PRICE;
	printf("%d", num);
	return 0;
}