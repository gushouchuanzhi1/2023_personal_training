#pragma once

void printArray(int array[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("this is the end of the algorithm!\n");
}

void selectSort(int array[], int len) {//ѡ������
	//ÿ�α���ȫ������С��������Ԫ���Ƶ�����
	//��һ���Ƚ���С���Ƶ���һλ���ڶ��α�����������С���Ƶ��ڶ�λ�Դ�����
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

void insertSort(int array[], int len) {//���������������˿���
	//����һ��Ԫ�ؿ���һ����������У����������Ϊû�������
	//������������У�������������ǰ������������м��ɡ�
	int cur = 0;
	int j = 0;
	for (int i = 1; i < len; i++) {
		cur = array[i];//��ǰδ��������е�һ��
		j = i - 1;
		while (j >= 0 && array[j] > cur) {
			array[j + 1] = array[j];//��������Ĳ��ұ�cur�����������
			j--;
		}
		array[j + 1] = cur;
	}
}

void shellSort(int array[], int len) {//�����ڲ��������Ȼ���Ϊ������У��ֱ��������Ȼ����ϸ��
	/*ѡ��һ���������� t1��t2��������tk������ ti > tj, tk = 1��
	���������и��� k�������н��� k ������
	ÿ�����򣬸��ݶ�Ӧ������ ti�����������зָ�����ɳ���Ϊ m �������У�
	�ֱ�Ը��ӱ����ֱ�Ӳ������򡣽���������Ϊ 1 ʱ��
	����������Ϊһ�������������ȼ�Ϊ�������еĳ��ȡ�*/
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

