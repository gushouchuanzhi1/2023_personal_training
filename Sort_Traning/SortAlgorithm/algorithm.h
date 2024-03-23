#pragma once

void printArray(int array[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("this is the end of the algorithm!\n");
}

void selectSort(int array[], int len) {
	//每次遍历全部找最小或者最大的元素移到排序
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


