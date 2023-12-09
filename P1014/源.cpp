#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	//第一排为1+1 第二排3 第三排4.。。
	int row = 1;
	int temp = n;
	while (temp - row > 0) {//temp row: 8 1;7 2;5 3;2 4;
		temp = temp - row;
		row++;
	}
	if (row % 2) {//从左下往右上
		int sum = row + 1;
		printf("%d/%d", sum - temp, temp);
	}
	else {//
		int sum = row + 1;
		printf("%d/%d", temp, sum - temp);
	}


	return 0;
}