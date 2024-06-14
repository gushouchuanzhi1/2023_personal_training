char* reverseWords(char* s) {
    int length = strlen(s);
    char *ret = (char*)malloc(sizeof(char) * (length + 1));
    int retIndex = 0;

    // 从字符串末尾开始遍历
    int i = length - 1;
    while (i >= 0) {
        // 跳过末尾的空格
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // 如果 i < 0，说明字符串结束
        if (i < 0) break;

        // 找到单词的结尾
        int end = i;

        // 找到单词的开头
        while (i >= 0 && s[i] != ' ') {
            i--;
        }
        
        // 将单词复制到 ret 中
        if (retIndex > 0) {
            ret[retIndex++] = ' ';
        }
        for (int j = i + 1; j <= end; j++) {
            ret[retIndex++] = s[j];
        }
    }

    // 添加字符串终止符
    ret[retIndex] = '\0';

    return ret;
}
