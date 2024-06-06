#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int FindMin(int arr[]) {
	int sz = sizeof(arr) / sizeof(arr[0]);
	int pos = 0;
	int min = arr[0];
	for (int i = 1; i < sz; i++) {
		if (arr[i] < min) {
			min = arr[i];
			pos = i;
		}
	}
	return pos;
}

int Remove(int* arr, int pos, int right) {
	if (right == pos) {//如果此时这里要求移除最右边的石头，这里的距离变化与左边的都不相同
		

	}
	else {//如果是前n-1块石头
		int add_dis = arr[pos];
		
	}

}

int main() {
	int l, n, m;//l为长度，n为总数量，m为移走数量
	scanf("%d %d %d", &l, &n, &m);
	int arr1[10005], arr2[10005];
	int right = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr1 + i);
		if (i == 0) {
			*(arr2 + i) = *(arr1 + i);
		}
		else {
			*(arr2 + i) = *(arr1 + i) - *(arr1 + i - 1);
		}
	}
	int pos = FindMin(arr2);//找到当前的最小的距离石头，移除
	//printf("%d\n", pos);




	/*for (int i = 0; i < n; i++) {
		printf("%d ", *(arr1 + i));
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", *(arr2 + i));
	}*/


	return 0;
}

