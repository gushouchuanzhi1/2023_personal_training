#include <stdio.h>

int main() {//需要注意精度问题，以及不同类型变量之间的类型统一
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