#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define ll long long
#define MAX_N 20 //��ΪN���ȡ��18

int n;
ll method[MAX_N][MAX_N];

ll caculate(int i, int j) {//method[i][j] i��ʾ����i������û�н�ջ��j��ʾջ�ڻ���j������
	if (method[i][j]) return method[i][j];
	if (i == 0) return 1;
	if (j > 0) {//��ջ�ڻ������ֵ�ʱ���ǿ��Գ�ջ�ģ���ջ�󻹿���ѡ���ջ������������ѡ�񷽷���
		method[i][j] += caculate(i, j - 1);
	}
	method[i][j] += caculate(i - 1, j + 1);//ջ�յ�ʱ��ֻ�ܽ�ջһ���������Ծ���i-1��j+1
	return method[i][j];
}

int main() {
	scanf("%d", &n);
	printf("%lld", caculate(n, 0));
	return 0;
}


