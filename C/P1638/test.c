#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int n, m, a[1000005], b[2005], k, ans, l, r, ll, rr;
//b[i]表示当前区间画家i的图画数
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	l = 1; r = 1; k = 1; b[a[1]] = 1; ans = 1000005;
	//k记录当前区间中有多少画家的图画
	while (l <= r && r <= n)
	{
		if (k == m)//判断是否符合要求
		{
			if (ans > r - l + 1)
			{
				ans = r - l + 1;//ans记录最小区间长度
				ll = l; rr = r;
				//ll记录最小区间的左端点,rr记录最小区间的右端点
			}
			b[a[l]]--;
			if (b[a[l]] == 0) k--;
			l++;
		}
		else {
			r++;
			b[a[r]]++;
			if (b[a[r]] == 1) k++;
		}
	}
	printf("%d %d", ll, rr);
	return 0;
}