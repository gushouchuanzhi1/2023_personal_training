/*
n+2行 第一行为地毯数量
后面n行 为地毯左上角以及向右上方向的长宽
最后一行为需要找的坐标
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;//地毯数量
	int a = 0, b = 0, g = 0, k = 0;//a为横坐标，b为纵坐标，g为横方向，k为竖方向
	int x = 0, y = 0;//需要查找的坐标
	scanf("%d", &n);
	int flag[10000][4] = { 0 };
	for (int i = 0; i < n; i++) {//将地毯的数据保存
		scanf("%d %d %d %d", &a, &b, &g, &k);
		int p = a + g;
		int q = b + k;
		flag[i][0] = a;
		flag[i][1] = b;
		flag[i][2] = p;
		flag[i][3] = q;
	}
	scanf("%d %d", &x, &y);
	int result = -1;
	for (int j = n - 1; j >= 0; j--) {
		if (x >= flag[j][0] && x <= flag[j][2] && y >= flag[j][1] && y <= flag[j][3]) {
			result = j + 1;
			printf("%d\n", result);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}


