#include <stdio.h>

int main() {//��Ҫע�⾫�����⣬�Լ���ͬ���ͱ���֮�������ͳһ
	int k = 0;
	scanf_s("%d", &k);
	long int i = 0;
	double sum = 0.0;
	while (sum <= k*1.0) {
		i++;
		double add = 1.0 / i;
		sum += add;
	}
	printf("%d", i);
}