int maximumProduct(int* nums, int numsSize) {
    if (numsSize == 3) {
        return nums[0] * nums[1] * nums[2];
    }
    int temp = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }//�Ӵ�С
    //��0��
    return fmax(nums[0] * nums[1] * nums[numsSize - 1], nums[numsSize - 3] * nums[numsSize - 2] * nums[numsSize - 1]);


}