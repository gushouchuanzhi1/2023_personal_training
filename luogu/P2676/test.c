#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  

int cow[20001], cnt;

void BubbleSort(int array[], int len) {
    for (int i = 0; i < len - 1; i++) { // 注意是 len - 1  
        for (int j = 0; j < len - i - 1; j++) { // 内层循环的结束条件也要调整  
            if (array[j] > array[j + 1]) { // 改为 > 来实现升序排序  
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    long long b;
    scanf("%d %lld", &n, &b); // 修改为 %lld 来正确读取 long long 类型的整数  
    for (int i = 0; i < n; i++) {
        scanf("%d", &cow[i]);
    }
    BubbleSort(cow, n);
    cnt = 0;
    int j = 0;
    while (cnt < b && j < n) { // 添加 j < n 来防止数组越界  
        cnt += cow[j];
        j++;
    }
    printf("%d\n", j);

    return 0;
}
