void reverseString(char* s, int sSize) {
    char c = s[0];
    if (sSize == 1) {
        return;
    }
    for (int i = 0; i < sSize / 2; i++) {
        c = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = c;
    }
    return;
}