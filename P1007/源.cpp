/*
独木桥 贪心算法 P1007

第一行为独木桥L
第二行士兵的数量N
第三行每个士兵的初始坐标
*/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, l, ans = 0, sna = 0;
int main()
{
	cin >> l >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		ans = max(min(l + 1 - a, a), ans);
		sna = max(max(l + 1 - a, a), sna);
	}
	cout << ans << ' ' << sna;
}