bool check(char* s, char* t) {
    int m = strlen(s), n = strlen(t);
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (s[i] == t[j]) {
            j++;
        }
        i++;
    }
    return j == n;
}

// 查找最长非公共子序列的长度
int findLUSlength(char** strs, int strsSize) {
    int res = -1;
    for (int i = 0; i < strsSize; i++) {
        bool flag = true;
        for (int j = 0; j < strsSize; j++) {
            if (i != j && check(strs[j], strs[i])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int len = strlen(strs[i]);
            if (len > res) res = len;
        }
    }
    return res;
}
