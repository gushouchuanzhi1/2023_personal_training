#include<stdio.h>
//P1008 将一到九，这九个数分成三组，每组组成一个三位数，
//并且可以实现这三个三位数构成一比二比三的比例，试求所有满足要求的三个三位数。

int main() {
	int number[9] = { 0 };
	for (int i = 123; i < 333; i++) {
		int a = i, b = 2 * i, c = 3 * i;
		number[0] = a / 100;
		number[1] = (a / 10) % 10;
		number[2] = a % 10;
		number[3] = b / 100;
		number[4] = (b / 10) % 10;
		number[5] = b % 10;
		number[6] = c / 100;
		number[7] = (c / 10) % 10;
		number[8] = c % 10;
		int flag = 1;
		for (int m = 0; m < 8; m++) {
			for (int n = m+1; n < 9; n++) {
				if (number[m] == number[n]) flag = 0;
			}
		}
		if (flag == 1) printf("%d %d %d\n", a, b, c);
	}
	return 0;
}