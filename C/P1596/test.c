#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void dfs(char grid[][101], int i, int j, int N, int M) {
    if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != 'W')
        return;

    grid[i][j] = '.'; // ���Ϊ�ѷ���

    // �������ڵİ˸�����
    dfs(grid, i + 1, j, N, M);
    dfs(grid, i - 1, j, N, M);
    dfs(grid, i, j + 1, N, M);
    dfs(grid, i, j - 1, N, M);
    dfs(grid, i + 1, j + 1, N, M);
    dfs(grid, i + 1, j - 1, N, M);
    dfs(grid, i - 1, j + 1, N, M);
    dfs(grid, i - 1, j - 1, N, M);
}

int countPonds(char grid[][101], int N, int M) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'W') {
                count++;
                dfs(grid, i, j, N, M);
            }
        }
    }
    return count;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    char grid[101][101];

    // ���ջ��з�
    getchar();

    // ��ȡ���ͼʾ
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%c", &grid[i][j]);
        }
        // ���ջ��з�
        getchar();
    }

    printf("%d\n", countPonds(grid, N, M));
    return 0;
}



