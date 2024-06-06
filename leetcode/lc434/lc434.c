

int countSegments(char* s) {
    int len = strlen(s);
    int ret = 0;
    if (len == 0) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
            ret++;
        }
    }
    //同时可以判断当前这个位置是字母并且前一个是空格

    return ret;
}