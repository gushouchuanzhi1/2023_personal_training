#include<iostream>
#include<cstring>
using namespace std;
int square[505][505], temp[505][505];

void spin(int x, int y, int r)//顺时针旋转90°
{
	for (int i = x - r; i <= x + r; i++)
	{
		for (int k = y - r; k <= y + r; k++)
			temp[i][k] = square[i][k];
	}
	int x1 = x + r, y1 = y - r;
	for (int i = x - r; i <= x + r; i++)
	{
		for (int k = y - r; k <= y + r; k++)
		{
			square[i][k] = temp[x1][y1];
			x1--;
		}
		x1 = x + r, y1++;
	}
}

void spin_(int x, int y, int r)//逆时针旋转90°
{
	for (int i = x - r; i <= x + r; i++)
	{
		for (int k = y - r; k <= y + r; k++)
			temp[i][k] = square[i][k];
	}
	int x1 = x - r, y1 = y + r;
	for (int i = x - r; i <= x + r; i++)
	{
		for (int k = y - r; k <= y + r; k++)
		{
			square[i][k] = temp[x1][y1];
			x1++;
		}
		y1--, x1 = x - r;
	}
}

int main()
{
	int n, m, t = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
			square[i][k] = ++t;
	}//首先给矩阵赋值
	int x, y, r, z;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> r >> z;
		if (z == 0)
			spin(x, y, r);
		else if (z == 1)
			spin_(x, y, r);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
			cout << square[i][k] << " ";
		cout << endl;
	}
}