

int maxRotateFunction(int* nums, int numsSize) {
    //k «0µΩnumsSize-1
    int f = 0, numSum = 0;
    for (int i = 0; i < numsSize; i++) {
        f += i * nums[i];
        numSum += nums[i];
    }
    int res = f;
    for (int i = numsSize - 1; i > 0; i--) {
        f += numSum - numsSize * nums[i];
        if (f >= res) {
            res = f;
        }
    }
    return res;
}