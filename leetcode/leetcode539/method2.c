#include <stdlib.h>
#include <stdio.h>

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
qsort(num, n, sizeof(int), cmp);
//ʹ��qsort���������򣬿���ʵ��nlogn��ʵ�����Ӷ�