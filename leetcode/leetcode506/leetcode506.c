/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char** ret = (char**)malloc(scoreSize * sizeof(char*));
    (*returnSize) = scoreSize;
    for (int i = 0; i < scoreSize; i++) {
        ret[i] = (char*)malloc(sizeof(char) * 13);
    }
    int* temp = (int*)malloc(sizeof(int) * scoreSize);
    memcpy(temp, score, sizeof(int) * scoreSize);
    qsort(temp, scoreSize, sizeof(int), cmp);
    for (int i = 0; i < scoreSize; i++) {
        for (int j = 0; j < scoreSize; j++) {
            if (score[i] == temp[j]) {
                if (j == scoreSize - 1) {
                    sprintf(ret[i], "%s", "Gold Medal");
                }
                else if (j == scoreSize - 2) {
                    sprintf(ret[i], "%s", "Silver Medal");
                }
                else if (j == scoreSize - 3) {
                    sprintf(ret[i], "%s", "Bronze Medal");
                }
                else {
                    sprintf(ret[i], "%d", scoreSize - j);
                }
            }
        }
    }
    return ret;
}
