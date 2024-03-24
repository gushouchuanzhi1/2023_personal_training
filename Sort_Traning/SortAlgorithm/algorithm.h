#pragma once

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

