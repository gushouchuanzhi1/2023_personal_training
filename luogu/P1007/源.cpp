/*
��ľ�� ̰���㷨 P1007

��һ��Ϊ��ľ��L
�ڶ���ʿ��������N
������ÿ��ʿ���ĳ�ʼ����
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