#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)；

int main() {
	int l = 0, m = 0, start = 0, end = 0;
	scanf("%d %d", &l, &m);//马路长度以及区间数目
	int tree[10005];
	for (int i = 0; i <= l; i++) {
		*(tree + i) = 1;
	}
	int move_cnt = 0;
	for (int j = 0; j < m; j++) {
		scanf("%d %d", &start, &end);
		for (int m = start; m <= end; m++) {
			if (*(tree + m) == 1) {
				*(tree + m) = 0;
				move_cnt++;
			}
			else continue;
		}
	}
	printf("%d", l - move_cnt + 1);
	return 0;
}

