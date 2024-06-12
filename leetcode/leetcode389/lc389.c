char findTheDifference(char* s, char* t) {
    int a[26] = { 0 };
    for (int i = 0; i < strlen(s); i++) {
        a[s[i] - 'a']++;
    }
    for (int j = 0; j < strlen(t); j++) {
        a[t[j] - 'a']--;
        if (a[t[j] - 'a'] < 0) {
            return t[j];
        }
    }
    return 'a';
}