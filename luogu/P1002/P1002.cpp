#include<iostream>
#include<algorithm>
using namespace std;
long long dp[30][30];
int m_x[8] = { -2,-2,-1,-1,1,1,2,2 }, m_y[8] = { 1,-1,2,-2,2,-2,1,-1 };//马跳的坐标变化

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    n += 1; m += 1; x += 1; y += 1;//整体空出一行一列，便于边界检查
    for (int i = 0; i < 8; i++) {
        if (x + m_x[i] >= 1 && x + m_x[i] <= n && y + m_y[i] >= 1 && y + m_y[i] <= m)
            dp[x + m_x[i]][y + m_y[i]] = -1;
    }
    dp[1][0] = 1;
    dp[x][y] = -1;//马所在的点也不能走
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == -1)
                dp[i][j] = 0;
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    cout << dp[n][m];

    system("pause");
    return 0;
}
