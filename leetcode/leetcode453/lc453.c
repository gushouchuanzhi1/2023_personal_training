

int minMoves(int* nums, int numsSize) {
    int min = nums[0], ret = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    for (int i = 0; i < numsSize; i++) {
        ret = ret + nums[i] - min;
    }
    return ret;
}