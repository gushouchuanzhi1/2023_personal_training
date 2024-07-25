int compare(const void* a, const void* b) {
    char num1[30], num2[30];

    // 将两个整数拼接成两种组合字符串
    sprintf(num1, "%d%d", *(int*)a, *(int*)b);
    sprintf(num2, "%d%d", *(int*)b, *(int*)a);

    // 使用 strcmp 比较拼接后的字符串
    return strcmp(num2, num1);
}

char* largestNumber(int* nums, int numsSize) {
    // 特殊情况处理：数组为空
    if (numsSize == 0) {
        return "";
    }
    // 使用 qsort 进行排序
    qsort(nums, numsSize, sizeof(int), compare);

    // 特殊情况：如果排序后最大的数字是 0，直接返回 "0"
    if (nums[0] == 0) {
        return "0";
    }

    // 分配足够大的字符串存储结果
    char* result = (char*)malloc(sizeof(char) * 1000);
    result[0] = '\0';

    // 拼接排序后的数字
    for (int i = 0; i < numsSize; i++) {
        char buffer[12];
        sprintf(buffer, "%d", nums[i]);
        strcat(result, buffer);
    }

    return result;
}