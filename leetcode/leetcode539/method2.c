#include <stdlib.h>
#include <stdio.h>

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
qsort(num, n, sizeof(int), cmp);
//使用qsort来进行排序，可以实现nlogn的实践复杂度