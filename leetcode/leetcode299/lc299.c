char* getHint(char* secret, char* guess) {
    int length = strlen(secret);
    int cnt_a = 0, cnt_b = 0;
    int flag_s[10] = { 0 };
    int flag_g[10] = { 0 };
    for (int i = 0; i < length; i++) {
        if (secret[i] == guess[i]) {//为公牛的
            cnt_a++;
            continue;//跳过后续判断
        }
        if (secret[i] != guess[i]) {
            flag_s[secret[i] - '0']++;
            flag_g[guess[i] - '0']++;
        }
    }
    for (int j = 0; j < 10; j++) {
        if (flag_g[j] == 0) continue;
        cnt_b += (flag_g[j] > flag_s[j]) ? flag_s[j] : flag_g[j];
    }
    // 为结果字符串分配足够的空间
    char* res = (char*)malloc(10 * sizeof(char));
    if (res == NULL) {
        return NULL; // 如果内存分配失败，返回NULL
    }
    sprintf(res, "%dA%dB", cnt_a, cnt_b);
    return res;

}