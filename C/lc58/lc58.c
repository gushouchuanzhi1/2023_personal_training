int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int cnt = 0;
    int i = len - 1;
    int flag = 0;
    while (i >= 0) {
        if (s[i] == ' ' && flag == 0) {
            i--;
            continue;
        }
        if (s[i] == ' ' && flag == 1) {
            break;
        }
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            cnt++;
            i--;
            flag = 1;
            continue;
        }
    }
    return cnt;
}