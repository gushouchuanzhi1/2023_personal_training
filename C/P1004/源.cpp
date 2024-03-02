#include<iostream>
#include<algorithm>
using namespace std;
int mp[15][15];
int dp[15][15][15][15];
int main()
{
	int n;
	cin >> n;
	int x, y, v;
	while (cin >> x >> y >> v)
	{
		if (x == 0 && y == 0 && v == 0)
			break;
		mp[x][y] = v;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				for (int l = 1; l <= n; l++)
				{
					//һ���ĸ�����
					int temp1 = max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]);
					int temp2 = max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1]);
					dp[i][j][k][l] = max(temp1, temp2) + mp[i][j];
					if (i != k && j != l)//��������ߵĲ���ͬ������mp[k][l]��ֵ
						dp[i][j][k][l] += mp[k][l];
				}
			}
		}
	}
	cout << dp[n][n][n][n] << endl;//���մ�
	return 0;
}

