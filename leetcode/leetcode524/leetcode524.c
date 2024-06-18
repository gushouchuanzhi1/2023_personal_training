bool check(char* s, char* a) {
    int m = strlen(s);
    int n = strlen(a);
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (s[i] == a[j]) {
            j++;
        }
        i++;
    }
    return j == n;
}

// 在字典中查找最长的子序列单词
char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    if (s == NULL || dictionary == NULL || dictionarySize == 0) {
        return NULL;
    }
    
    int maxLen = 0;
    char* result = NULL;

    for (int i = 0; i < dictionarySize; i++) {
        char* word = dictionary[i];
        if (check(s, word)) {
            int wordLen = strlen(word);
            if (wordLen > maxLen || (wordLen == maxLen && strcmp(word, result) < 0)) {
                maxLen = wordLen;
                result = word;
            }
        }
    }

    return result ? result : "";
}