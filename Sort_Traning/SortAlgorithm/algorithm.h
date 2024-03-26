#pragma once
#include <stdio.h>
#include <malloc.h>
void printArray(int array[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("this is the end of the algorithm!\n");
}

void selectSort(int array[], int len) {//选择排序
	//每次遍历全部找最小或者最大的元素移到排序
	//第一次先将最小的移到第一位，第二次遍历后续将最小的移到第二位以此类推
	int min = 0, temp = 0;
	for (int i = 0; i < len - 1; i++) {
		min = i;
		for (int j = i + 1; j < len; j++) {
			if (array[min] > array[j]) {
				int temp = array[j];
				array[j] = array[min];
				array[min] = temp;
			}
		}
	}
}

void insertSort(int array[], int len) {//插入排序，类似于扑克牌
	//将第一个元素看作一个有序的数列，后面的数列为没有排序的
	//遍历后面的数列，逐个将其插入在前面的有序数列中即可。
	int cur = 0;
	int j = 0;
	for (int i = 1; i < len; i++) {
		cur = array[i];//当前未排序的数列第一个
		j = i - 1;
		while (j >= 0 && array[j] > cur) {
			array[j + 1] = array[j];//将已排序的并且比cur大的数往后移
			j--;
		}
		array[j + 1] = cur;
	}
}

void shellSort(int array[], int len) {//类似于插入排序，先划分为大的序列，分别进行排序，然后再细分
	/*选择一个增量序列 t1，t2，……，tk，其中 ti > tj, tk = 1；
	按增量序列个数 k，对序列进行 k 趟排序；
	每趟排序，根据对应的增量 ti，将待排序列分割成若干长度为 m 的子序列，
	分别对各子表进行直接插入排序。仅增量因子为 1 时，
	整个序列作为一个表来处理，表长度即为整个序列的长度。*/
	int gap = 0, i = 0, j = 0;
	int temp = 0;
	for (gap = len >> 1; gap > 0; gap >> 1) {
		for (i = gap; i < len; i++) {
			temp = array[i];
			for (j = i - gap; j >= 0 && array[j] > temp; j -= gap) {
				array[j + gap] = array[j];
			}
			array[j + gap] = temp;
		}
	}
}

int min(int x, int y) {
	return x > y ? y : x;//三目表达式
}

void mergeSortRecursive(int array[], int reg[], int start, int end) {//归并算法进行递归   O(nlogn)
	/*本质上使用了分治算法，将整个数组不断二分，划分到只有单个元素
	分割到只有一个元素之后，两两归并，将其划分成有序的数列，最后将划分好的归并成一个完整的数列*/
	if (start >= end) {
		return;
	}
	int len = end - start, mid = (len >> 1) + start;//先求出当前的长度，分为一半
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	mergeSortRecursive(array, reg, start1, end1);
	mergeSortRecursive(array, reg, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2) {
		reg[k++] = array[start1] < array[start2] ? array[start1++] : array[start2++];
	}
	while (start1 <= end1) {
		reg[k++] = array[start1];
	}
	while (start2 <= end2) {
		reg[k++] = array[start2];
	}
	for (k = start; k <= end; k++) {
		array[k] = reg[k];
	}

}

void mergeSort(int array[], const int len) {//这里的 len 是 array 的长度，在递归的过程中始终不变
	int* reg = (int*)malloc(len * sizeof(int));
	mergeSortRecursive(array, reg, 0, len - 1);
	free(reg);
}

void Swap(int* x, int* y) {
	//&是取地址符，可看作对于你的变量进行操作
	//*是解地址符，可看作对于你的地址进行操作
	int temp = *y;
	*y = *x;
	*x = temp;
}


