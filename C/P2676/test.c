#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  

int cow[20001], cnt;

void BubbleSort(int array[], int len) {
    for (int i = 0; i < len - 1; i++) { // ע���� len - 1  
        for (int j = 0; j < len - i - 1; j++) { // �ڲ�ѭ���Ľ�������ҲҪ����  
            if (array[j] > array[j + 1]) { // ��Ϊ > ��ʵ����������  
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
    scanf("%d %lld", &n, &b); // �޸�Ϊ %lld ����ȷ��ȡ long long ���͵�����  
    for (int i = 0; i < n; i++) {
        scanf("%d", &cow[i]);
    }
    BubbleSort(cow, n);
    cnt = 0;
    int j = 0;
    while (cnt < b && j < n) { // ��� j < n ����ֹ����Խ��  
        cnt += cow[j];
        j++;
    }
    printf("%d\n", j);

    return 0;
}
