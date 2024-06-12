void rotate(int* nums, int numsSize, int k) {
    int newarray[numsSize];
    for (int i = 0; i < numsSize; i++) {
        newarray[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = newarray[i];
    }
}

