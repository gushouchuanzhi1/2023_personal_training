//主要思路就是先将输入的path按照/来分割成字符串数组，这里由于按照/分割，所以//不会视作目录可以正确处理
//对于分割形成的字符串数组，我们构造一个栈，栈里每个元素都是一个字符串，我们按照数组的顺序将他们入栈
//遇到..我们--stackSize，然后我们再判断. 如果当前字符串是一个正确的目录名我们就入栈，如果是.的话我们就跳过不处理即可。

char** split(char* s, char splitChar, int* arrayLength){
    int length = strlen(s);
    int returnlen = 0;//这个字符串数组的长度
    char** ans = (char**)malloc(sizeof(char*) * length);
    int start = 0, end = 0;
    while(end < length){
        while(end < length && s[end] == splitChar){//跳过当前连续的/
            end++;
        }
        start = end;
        while(end < length && s[end] != splitChar){//找当前的单词截止的位置
            end++;
        }
        if(start < length){
            ans[returnlen] = (char*)malloc(sizeof(char) * (end - start + 1));//+1是'\0'
            //将当前的目录名字复制过来
            strncpy(ans[returnlen], s + start, end - start);
            ans[returnlen][end - start] = '\0';
            returnlen++;
        }
    }
    *arrayLength = returnlen;
    return ans;
    
}

char* simplifyPath(char* path) {
    int arrayLength = 0;
    char** ret = split(path, '/', &arrayLength);
    char** stack = (char**)malloc(sizeof(char*) * arrayLength);
    int stackLength = 0;

    for (int i = 0; i < arrayLength; i++) {
        if (!strcmp(ret[i], "..")) {
            if (stackLength > 0) stackLength--;
        } else if (strcmp(ret[i], ".")) {
            stack[stackLength] = ret[i];
            stackLength++;
        }
    }

    char* ans = (char*)malloc(sizeof(char) * (strlen(path) + 1));
    int cur = 0;
    
    if (stackLength == 0) {
        ans[cur++] = '/';
    } else {
        for (int j = 0; j < stackLength; j++) {
            ans[cur++] = '/';
            strcpy(ans + cur, stack[j]);
            cur += strlen(stack[j]);
        }
    }

    ans[cur] = '\0';
    
    for (int i = 0; i < arrayLength; i++) {
        free(ret[i]);
    }
    free(ret);
    free(stack);
    
    return ans;
}