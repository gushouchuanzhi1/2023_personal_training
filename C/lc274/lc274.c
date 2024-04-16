int hIndex(int* citations, int citationsSize) {
    for (int i = 0; i < citationsSize - 1; i++) {
        for (int j = 0; j < citationsSize - 1 - i; j++) {
            if (citations[j] > citations[j + 1]) {
                int temp = citations[j];
                citations[j] = citations[j + 1];
                citations[j + 1] = temp;
            }
        }
    }
    int h = 0; int i = citationsSize - 1;
    while (i >= 0 && citations[i] > h) {
        h++;
        i--;
    }
    return h;
}