#include<stdio.h>
//P1008 ��һ���ţ���Ÿ����ֳ����飬ÿ�����һ����λ����
//���ҿ���ʵ����������λ������һ�ȶ������ı�����������������Ҫ���������λ����

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