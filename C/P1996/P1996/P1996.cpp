#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, m;//n个人，第m个人出圈
	int t = 0;
	scanf("%d %d", &n, &m);
	int array[105] = { 0 };
	for (int i = 0; i < n; i++) {//数组标记
		for (int j = 0; j < m; j++) {
			if (++t > n) t = 1;
			if (array[t]) j--;
		}
		printf("%d ", t);
		array[t] = 1;
	}
	return 0;
}




