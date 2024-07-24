int longestPalindrome(char* s) {
    int length = strlen(s);
    int cnt[56] = {0};
    for(int i = 0; i < length; i++){
        if(s[i] >= 'A' && s[i] <='Z'){
            cnt[s[i]-'A']++;
        }
        if(s[i] >= 'a' && s[i] <='z'){
            cnt[s[i]-'a'+26]++;
        }
    }
    int ret = 0;
    int flag = 0;//是否有1或者奇数
    for(int i = 0; i < 52; i++){
        if(cnt[i] % 2){
            flag = 1;
            ret = ret + cnt[i] - 1;
        }
        else{
            ret = ret + cnt[i];
        }
    }
    if(flag){
        ret = ret + 1;
    }
    return ret;
}