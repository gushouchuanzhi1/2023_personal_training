#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main() {
	char num1[5000], num2[5000];
	scanf("%s%s", num1, num2);
	int m = strlen(num1), n = strlen(num2);
	int a[5000], b[5000], res[5000];
	int i = 0, j = 0;
	for (i = 0, j = m - 1; i < m; i++, j--) {
		a[i] = num1[j] - '0';
	}
	for (i = 0, j = n - 1; i < n; i++, j--) {
		b[i] = num2[j] - '0';
	}
	for (i = 0; i < 5000; i++) {
		res[i] = 0;
	}
	int carry = 0;

	for (i = 0; i < m || i < n; i++) {
		int sum = carry;
		if (i < n) {
			sum += a[i];
		}
		if (i < m) {
			sum += b[i];
		}
		res[i] = sum % 10;
		carry = sum / 10;
	}
	if (carry > 0) {
		res[i] = carry;
	}
	for (j = i - 1; j >= 0; j--) {
		printf("%d", res[j]);
	}
	printf("\n");

	return 0;
}


