#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>//����ͷ
using namespace std;
int n, len;//����������������ַ����ܳ�
char a1[300], b1[300], z;
int len1[300], len2[300], len3[300];//����������2��+��������
char len4[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };//26����ĸ
char len5[10] = { '0','1','2','3','4','5','6','7','8','9' };//10������
int main()
{
	memset(len1, 0, sizeof(len1));//����
	memset(len2, 0, sizeof(len2));//����
	cin >> n;
	cin >> a1;
	cin >> b1;
	int n1 = strlen(a1), n2 = strlen(b1);//����ͳ��a1,b1����
	for (int i = 0; i < n1; i++)
	{
		if (a1[i] >= '0' && a1[i] <= '9') len1[n1 - i] = a1[i] - 48;//���������ʹ��������
		else len1[n1 - i] = a1[i] - 'a' + 10;//�������ĸ�ʹ��������
	}
	for (int i = 0; i < n2; i++)
	{
		if (b1[i] >= '0' && b1[i] <= '9')  len2[n2 - i] = b1[i] - 48;//ͬ��
		else len2[n2 - i] = b1[i] - 'a' + 10;//ͬ��
	}
	int t = max(n1, n2);//���ĳ��ȣ������������ճ��ȣ���Ϊ�������λ���λ��
	for (int i = 1; i <= t; i++)
	{
		len3[i] += len1[i]; len3[i] += len2[i];//���
		if (len3[i] >= n)
		{
			len3[i] -= n;
			len3[i + 1]++;
		} //��λ����
	}
	for (int i = 201; i >= 1; i--)
	{
		if (len3[i] != 0)
		{
			len = i;
			break;
		}
	}//ͳ�����ճ���
	for (int i = len; i >= 1; i--)
	{
		z = 'a' + len3[i] - 10;
		if (len3[i] < 10) cout << len3[i];//����ܴ�������־��������
		else cout << z;//���������ĸ
	}
	return 0;
}