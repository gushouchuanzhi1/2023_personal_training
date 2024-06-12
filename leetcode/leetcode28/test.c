int strStr(char* haystack, char* needle) {
    int m = strlen(haystack), n = strlen(needle);
    if (m < n) return -1;
    for (int i = 0; i + n <= m; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            return i;
        }

    }
    return -1;
}