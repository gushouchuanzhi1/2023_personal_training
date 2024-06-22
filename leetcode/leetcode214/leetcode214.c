bool checkReverse(char* s){
    int length = strlen(s);
    for(int i = 0; i < length / 2; i++){
        if(s[i] != s[length - 1 - i]){
            return false;
        }
    }
    return true;
}

void getSubString(char* s, int num, char* res){//从s中截取前num个字符，并且通过res传出函数中
    int i = 0;
    for(i = 0; i < num; i++){
        res[i] = s[i];
    }
    s[i] = '\0';
}

char* shortestPalindrome(char* s) {
    int length = strlen(s);//题目输入的字符串s的长度
    int i = 0;
    if(length == 0){
        return "";
    }
    char* temp = (char*)malloc(sizeof(char) * (length + 1));
    strcpy(temp, s);
    char* ret=(char*)malloc(sizeof(char) * (2 * length +1));
    for(i = length - 1; i >= 0; i--){
        if(checkReverse(temp) == false){
            ret[length - i - 1] = temp[i]; 
            //如果这个字符串不是回文串，那么当前的这个字符肯定要被复制到ret的开头
            temp[i] = 0;
        }
        else{
            ret[length - i - 1] = 0;break;
        }
    }
    strcat(ret, s);//追加一个s，因为这里的ret只有需要复制的这一部分
    return ret; 
}