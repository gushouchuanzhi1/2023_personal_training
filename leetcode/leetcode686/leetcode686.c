int repeatedStringMatch(char* a, char* b) {
    //b字符串中一定会有一个完整的a，如果没有的话就可以直接返回了
    //如果需要返回-1，还需要判断前后的字符能否符合a，这就可以前后逆序和顺序遍历
    //如果要求能够有多少次重复，先判断这个里面有多少个完全重复的字符串a
    //假设有m个重复的字符串a，a的字符串长度是length，那么b的长度就是，m * length m * length + (length - 1)*2

    //strstr函数，可以返回b在a中第一次出现的位置 小丑了
    int m = strlen(a), n = strlen(b);
    int max = n / m + 2;
    char* resstr = (char*)malloc(sizeof(char) * (max * m + 1));
    memset(resstr,'\0',max * m + 1);
    for(int i = 0; i < max; i++){
        strcat(resstr, a);//往里面追加一个字符串
        char * temp = NULL;
        if(strlen(resstr) >= n){
            temp = strstr(resstr, b);
        }
        if(temp == NULL){//这里包含了找不到b和resstr长度还不够的情况。
            continue;
        }
        else{//如果这里长度超过b然后已经可以找到b了，那么可以返回当前复制的次数了，i从0开始的多+1
            return i + 1;
        }
    }
    free(resstr);
    return -1;
}