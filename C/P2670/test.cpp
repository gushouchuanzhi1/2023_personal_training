#include<bits/stdc++.h>
using namespace std;
bool a[105][105];
int main()
{
    memset(a, 0, sizeof(a));
    int n, m;
    char tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tmp;
            if (tmp == '*') a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1) printf("*");
            else
            {
                printf("%d", a[i + 1][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i][j + 1] + a[i][j - 1] + a[i - 1][j + 1] + a[i - 1][j] + a[i - 1][j - 1]);
                
            }
        }
        printf("\n");
    }
    return 0;
}