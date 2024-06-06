/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] != nums[nums[i] - 1]) {
            int tmp = nums[i];
            nums[i] = nums[tmp - 1];
            nums[tmp - 1] = tmp;
        }
    }
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] - 1 != j) {
            ret[*returnSize] = nums[j];
            (*returnSize)++;
        }
    }
    return ret;
}