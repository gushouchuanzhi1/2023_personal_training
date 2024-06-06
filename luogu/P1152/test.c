#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 1000
int array1[MAX];
int array2[MAX] = { 0 };

int abs(int a) {
	return a > 0 ? a : -a;
}

int main() {
	int n;
	scanf("%d", &n);
	int number;
	for (int i = 0; i < n; i++) {
		scanf("%d", &array1[i]);
	}
	for (int j = 1; j < n; j++) {//没有考虑数组存储溢出的时候
		array2[abs(array1[j] - array1[j - 1])]++;
	}
	for (int m = 0; m < n - 1; m++) {
		if (array2[m] == 0 || array2[m] > 1) {
			printf("Not jolly\n");
			return;
		}
	}
	printf("Jolly\n");

	return 0;
}

