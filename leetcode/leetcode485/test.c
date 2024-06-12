int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0;
    int temp = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            temp += 1;
        }
        else {
            if (max < temp) {
                max = temp;
            }
            temp = 0;
        }
    }
    if (max < temp) {
        max = temp;
    }
    return max;
}