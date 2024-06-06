#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAX_N 20
#define MAX_X 5000000

int n, k;
int nums[MAX_N];
bool visited[MAX_N]; // 新增的标记数组
int count = 0;

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int start, int selected, int total) {
    if (selected == k) {
        if (is_prime(total)) count++;
        return;
    }
    for (int i = start; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true; // 标记当前位置的数字被选取
            dfs(i + 1, selected + 1, total + nums[i]);
            visited[i] = false; // 回溯时取消标记
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    dfs(0, 0, 0);
    printf("%d\n", count);
    return 0;
}