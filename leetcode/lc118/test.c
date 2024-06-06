/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ret = malloc(sizeof(int*) * numRows);//这个指保存了numRows个数组
    *returnSize = numRows;//这个是ret中的数组数量，直接指向数量
    *returnColumnSizes = malloc(sizeof(int) * numRows);//每一行作为一个数组，长度为行数
    for (int i = 0; i < numRows; i++) {
        ret[i] = malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        ret[i][0] = 1;
        ret[i][i] = 1;
        for (int j = 1; j < i; j++) {
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
    }
    return ret;

}