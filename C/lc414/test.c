int thirdMax(int* nums, int numsSize) {
    int temp;
    for (int i = 0; i < numsSize - 1; i++) {//由大到小排序
        for (int j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] < nums[j + 1]) {
                temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    int differnt = 1;
    temp = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != temp) {
            differnt++;
            temp = nums[i];
        }
        if (differnt == 3) {
            return temp;
        }
    }
    return nums[0];
}