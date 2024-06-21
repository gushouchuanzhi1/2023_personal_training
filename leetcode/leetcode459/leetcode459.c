bool repeatedSubstringPattern(char* s) {
    int length = strlen(s);
    for(int i = 1; i * 2 <= length; i++){
        if(length % i == 0){//只有可以完整重复的字符串才符合
            bool match = true;
            for(int j = i; j < length; j++){
                if(s[j] != s[j-i]){//从s中的第二个单位字符串长度开始，向前面一个单位进行比较，
                    //不用全部放一起比较了
                    match = false;
                    break;
                }
            }    
            if(match){
                return true;//当前的i已经可以满足了就直接返回就好了
            }        
        } 
    }
    return false;//所有长度的i都不符合
}