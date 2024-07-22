int distributeCandies(int* candyType, int candyTypeSize) {
    int* hashSet = (int*)malloc(sizeof(int) * 200001); // 根据题目范围，假设糖果类型的范围是 [-100000, 100000]
    for (int i = 0; i < 200001; i++) {
        hashSet[i] = 0;
    }

    int uniqueCandies = 0;
    for (int i = 0; i < candyTypeSize; i++) {
        int index = candyType[i] + 100000; // 将范围调整到 [0, 200000]
        if (hashSet[index] == 0) {
            uniqueCandies++;
            hashSet[index] = 1;
        }
    }
    
    free(hashSet);

    return (uniqueCandies < candyTypeSize / 2) ? uniqueCandies : candyTypeSize / 2;
}