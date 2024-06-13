char* reverseWords(char* s) {
    int length = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (length+1));
    res[length] = '\0';
    int i = 0;
    while(i < length){
        int start = i;
        while(i < length&&s[i]!=' '){
            i++;
        }
        for(int p = start; p < i; p++){
            res[p] = s[start + i - p - 1];//通过start记录每个单词开头的位置，使用p将单词[start,i]中间逆序输入res
        }
        while(i < length && s[i]==' '){
            res[i] = ' ';
            i++;
        }
    }
    return res;
}