#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, k, res[201][7];
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		res[i][1] = 1;
		res[i][0] = 1;
	}
	for (int i = 2; i <= k; i++) {
		res[1][i] = 0;
		res[0][i] = 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			if (i > j) res[i][j] = res[i - 1][j - 1] + res[i - j][j];
			else res[i][j] = res[i - 1][j - 1];
		}
	}
	printf("%d", res[n][k]);

	return 0;
}