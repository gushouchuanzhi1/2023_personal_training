bool isPalindrome(char* s) {
    int len = strlen(s);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')) {
            s[cnt] = s[i];
            cnt++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[cnt] = s[i] + 32;
            cnt++;
        }
    }
    //cnt现在是需要判断回文串的长度
    for (int i = 0; i < cnt / 2; i++) {
        if (s[i] == s[cnt - 1 - i]);
        else {
            return false;
        }
    }
    return true;
}