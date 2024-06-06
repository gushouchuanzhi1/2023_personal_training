#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define ll long long
#define MAX_N 20 //因为N最多取到18

int n;
ll method[MAX_N][MAX_N];

ll caculate(int i, int j) {//method[i][j] i表示还有i个数字没有进栈，j表示栈内还有j个数字
	if (method[i][j]) return method[i][j];
	if (i == 0) return 1;
	if (j > 0) {//当栈内还有数字的时候，是可以出栈的，出栈后还可以选择进栈，所以有两种选择方法。
		method[i][j] += caculate(i, j - 1);
	}
	method[i][j] += caculate(i - 1, j + 1);//栈空的时候，只能进栈一个数字所以就是i-1和j+1
	return method[i][j];
}

int main() {
	scanf("%d", &n);
	printf("%lld", caculate(n, 0));
	return 0;
}


