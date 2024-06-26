int calPoints(char** operations, int operationsSize) {
    int* rec = (int*)malloc(sizeof(int) * operationsSize);
    int length = 0; // 有多少个有效的操作数

    for (int i = 0; i < operationsSize; i++) {
        if (isdigit(operations[i][0]) || (operations[i][0] == '-' && isdigit(operations[i][1]))) {
            rec[length] = atoi(operations[i]);
            length++;
        } else if (operations[i][0] == '+') {
            rec[length] = rec[length - 1] + rec[length - 2];
            length++;
        } else if (operations[i][0] == 'D') {
            rec[length] = rec[length - 1] * 2;
            length++;
        } else if (operations[i][0] == 'C') {
            length--;
        }
    }

    int ret = 0;
    for (int j = 0; j < length; j++) {
        ret += rec[j];
    }

    free(rec); // 释放分配的内存
    return ret;
}