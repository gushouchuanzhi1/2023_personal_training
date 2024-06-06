bool detectCapitalUse(char* word) {
    int len = strlen(word);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            cnt++;
        }
    }
    if (cnt == 1 && word[0] >= 'A' && word[0] <= 'Z') {
        return true;
    }
    if (cnt == 0) {
        return true;
    }
    if (cnt == len) {
        return true;
    }
    return false;
}