//这里的函数起的作用是只把里面的单词整个顺序不变，然后调整顺单词的顺序，但是对于字符串里的空格并没有按照要求处理
char* reverseWords(char* s) {
    int length = strlen(s);
    char *ret = (char*)malloc(sizeof(char)*(length+1));
    
    int i = length-1;
    while(i >= 0){
        int start = i;
        while(i >= 0&& s[i] != ' '){
            i--;
        }
        for(int p = i+1; p <= start; p++){
            ret[length-1-start + p-i-1] = s[p];
        }
        while(i >= 0 && s[i]==' '){
            ret[length-1-i]=' ';
            i--;
        }
    }
    ret[length] = '\0';
    return ret;
}