#include <stdio.h>
#define CHAIR 30

int main() {
	int high[10];
	int height = 0;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", high + i);
	}
	scanf_s("%d", &height);
	int cnt = 0;
	for (int j = 0; j < 10; j++) {
		if (height + CHAIR >= *(high + j)) cnt++;
		else continue;
	}
	printf("%d", cnt);
	return 0;
}



