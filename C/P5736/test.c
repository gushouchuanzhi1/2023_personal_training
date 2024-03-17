#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int num) {
	if (num == 1) return false;
	if (num == 2) return true;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int num = 0;
	scanf("%d", &num);
	int res[100];
	for (int i = 0; i < num; i++) {
		scanf("%d", &res[i]);
		if (isPrime(res[i])) {
			continue;
		}
		else {
			res[i] = 0;
		}
	}
	for (int i = 0; i < num; i++) {
		if (res[i] != 0) {
			printf("%d ", res[i]);
		}
		else { continue; }
	}

	return 0;
}

