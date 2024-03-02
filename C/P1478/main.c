#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 5000

int main() {
	int n = 0, s = 0;
	int a = 0, b = 0;
	int apple[MAX];
	scanf("%d %d", &n, &s);
	scanf("%d %d", &a, &b);
	int max = a + b;//the max of x below
	int count = 0;//the apple she can get
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		if (x <= max) {
			apple[count] = y;
			count++;
		}
	}
	//比较元素大小
	for (int m = 0; m < count - 1; m++) {
		for (int n = 0; n < count - 1 - m; n++) {
			if (apple[n] >= apple[n + 1]) {
				int temp = apple[n];
				apple[n] = apple[n + 1];
				apple[n + 1] = temp;
			}
		}
	}
	int res = 0, remain = s;
	for (int p = 0; p < count; p++) {
		//printf("%d ", remain);

		if (remain - apple[p] < 0) {
			break;
		}
		else {
			remain = remain - apple[p];
			res++;
		}
	}
	//printf("\n");
	printf("%d\n", res);

	return 0;

}



