#include<stdio.h>

#define N 250//2000位够了，250*8

int  f[3][N + 10], g;
int n;
int main()
{
	f[0][N] = 1; f[1][N] = 1; scanf("%d", &n); if (!n) { puts("0"); return 0; }//0要特判
	for (int i = 2; i <= n; i++)
		for (int j = N; j > 0; j--)
		{
			f[i % 3][j] = (f[(i + 1) % 3][j] + f[(i + 2) % 3][j] + g) % 100000000;
			g = (f[(i + 1) % 3][j] + f[(i + 2) % 3][j] + g) / 100000000;//8个0，别漏了
		}
	int j = 1;
	while (!f[n % 3][j] && j < N) j++;//处理前导0
	for (int i = j; i <= N; i++)
	{
		if (i != j) {//一定别漏了前面这句
			if (f[n % 3][i] < 1e7) putchar(48);
			if (f[n % 3][i] < 1e6) putchar(48);
			if (f[n % 3][i] < 1e5) putchar(48);
			if (f[n % 3][i] < 1e4) putchar(48);
			if (f[n % 3][i] < 1e3) putchar(48);
			if (f[n % 3][i] < 1e2) putchar(48);
			if (f[n % 3][i] < 1e1) putchar(48);
		}//补足前导0
		printf("%d", f[n % 3][i]);//输出
	}
}