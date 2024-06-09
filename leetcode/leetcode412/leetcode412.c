

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** r = (char**)malloc(n * sizeof(char*));
    for (int i = 1; i <= n; i++)
    {
        r[i - 1] = (char*)calloc(10, 1);
        if ((i % 15) == 0)
            strcpy(r[i - 1], "FizzBuzz");
        else if ((i % 3) == 0)
            strcpy(r[i - 1], "Fizz");
        else if ((i % 5) == 0)
            strcpy(r[i - 1], "Buzz");
        else
            sprintf(r[i - 1], "%d", i);
    }
    return r;
}