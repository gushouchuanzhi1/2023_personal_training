/*
n+2�� ��һ��Ϊ��̺����
����n�� Ϊ��̺���Ͻ��Լ������Ϸ���ĳ���
���һ��Ϊ��Ҫ�ҵ�����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;//��̺����
	int a = 0, b = 0, g = 0, k = 0;//aΪ�����꣬bΪ�����꣬gΪ�᷽��kΪ������
	int x = 0, y = 0;//��Ҫ���ҵ�����
	scanf("%d", &n);
	int flag[10000][4] = { 0 };
	for (int i = 0; i < n; i++) {//����̺�����ݱ���
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


