typedef struct {
    int idx;
    int timestamp;
} Pair;

int* exclusiveTime(int n, char ** logs, int logsSize, int* returnSize) {
    Pair *stack = (Pair *)malloc(sizeof(Pair)* logsSize); // {idx, 开始运行的时间}
    int *res = (int *)malloc(sizeof(int) * n);
    memset(res, 0, sizeof(int) * n);
    int top = 0;
    for (int i = 0; i < logsSize; i++) {
        char type[10];
        int idx, timestamp;
        sscanf(logs[i], "%d:%[^:]:%d", &idx, type, &timestamp);
        if (type[0] == 's') {
            if (top > 0) {
                res[stack[top - 1].idx] += timestamp - stack[top - 1].timestamp;
                stack[top - 1].timestamp = timestamp;
            }
            stack[top].idx = idx;
            stack[top].timestamp = timestamp;
            top++;
        } else {
            res[stack[top - 1].idx] += timestamp - stack[top - 1].timestamp + 1;
            top--;
            if (top > 0) {
                stack[top - 1].timestamp = timestamp + 1;
            }
        }
    }
    free(stack);
    *returnSize = n;
    return res;
}