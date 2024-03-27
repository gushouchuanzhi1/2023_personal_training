#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main() {
	int a, b, c;
	int cnt_ans = 0;
	int flag[10] = { 0 };
	scanf("%d%d%d", &a, &b, &c);
	if (a == 0 || b == 0 || c == 0) {
		printf("No!!\n");
		return;
	}
	//printf("%d %d %d\n", a, b, c);
	int max = 1000 / c;
	int m, n, q;
	int print_flag = 1;
	
	for (int i = 1; i <= max; i++) {
		m = i * a; 
		n = i * b; 
		q = i * c;
		if (m > 999 || n > 999 || q > 999) {
			break;
		}
		for (int p = 1; p <= 3; p++) {
			flag[m % 10]++;
			m = m / 10;
		}
		for (int p = 1; p <= 3; p++) {
			flag[n % 10]++;
			n = n / 10;
		}
		for (int p = 1; p <= 3; p++) {
			flag[q % 10]++;
			q = q / 10;
		}
		for (int p = 1; p < 10; p++) {
			if (flag[p] != 1) {
				print_flag = 0;
				break;
			}
		}
		for (int p = 1; p < 10; p++) {
			flag[p] = 0;
		}
		if (print_flag) {
			printf("%d %d %d\n", a * i, b * i, c * i);
			cnt_ans++;
		}
		else print_flag = 1;
	}
	if (cnt_ans == 0) printf("No!!\n");


	return 0;

}

