#include<bits/stdc++.h>
using namespace std;
int x[5000005], k;
void qsort(int l, int r)
{
	int i = l, j = r, mid = x[(l + r) / 2];
	do
	{
		while (x[j] > mid)
			j--;
		while (x[i] < mid)
			i++;
		if (i <= j)
		{
			swap(x[i], x[j]);
			i++;
			j--;
		}
	} while (i <= j);
	//���ź����鱻����Ϊ���飺 l<=j<=i<=r
	if (k <= j) qsort(l, j);//��������ֻ��Ҫ��������
	else if (i <= k) qsort(i, r);//��������ֻ��Ҫ��������
	else //������м�����ֱ�����
	{
		printf("%d", x[j + 1]);
		exit(0);
	}
}
int main()
{
	int n;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	qsort(0, n - 1);
}