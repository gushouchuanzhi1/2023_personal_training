#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>//万能头
using namespace std;
int n, len;//进制数及最终输出字符串总长
char a1[300], b1[300], z;
int len1[300], len2[300], len3[300];//处理后的数字2组+最终数字
char len4[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };//26个字母
char len5[10] = { '0','1','2','3','4','5','6','7','8','9' };//10个数字
int main()
{
	memset(len1, 0, sizeof(len1));//归零
	memset(len2, 0, sizeof(len2));//归零
	cin >> n;
	cin >> a1;
	cin >> b1;
	int n1 = strlen(a1), n2 = strlen(b1);//函数统计a1,b1长度
	for (int i = 0; i < n1; i++)
	{
		if (a1[i] >= '0' && a1[i] <= '9') len1[n1 - i] = a1[i] - 48;//如果是数组就处理成数字
		else len1[n1 - i] = a1[i] - 'a' + 10;//如果是字母就处理成数字
	}
	for (int i = 0; i < n2; i++)
	{
		if (b1[i] >= '0' && b1[i] <= '9')  len2[n2 - i] = b1[i] - 48;//同上
		else len2[n2 - i] = b1[i] - 'a' + 10;//同上
	}
	int t = max(n1, n2);//最大的长度（并不代表最终长度！因为可能最高位会进位）
	for (int i = 1; i <= t; i++)
	{
		len3[i] += len1[i]; len3[i] += len2[i];//相加
		if (len3[i] >= n)
		{
			len3[i] -= n;
			len3[i + 1]++;
		} //进位操作
	}
	for (int i = 201; i >= 1; i--)
	{
		if (len3[i] != 0)
		{
			len = i;
			break;
		}
	}//统计最终长度
	for (int i = len; i >= 1; i--)
	{
		z = 'a' + len3[i] - 10;
		if (len3[i] < 10) cout << len3[i];//如果能处理成数字就输出数字
		else cout << z;//否则输出字母
	}
	return 0;
}