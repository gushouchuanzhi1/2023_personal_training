int firstUniqChar(char* s) {
    int a[26] = { 0 };
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        a[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++) {
        if (a[s[i] - 'a'] == 1) return i;
    }

    return -1;

}