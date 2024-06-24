char* convertToBase7(int num) {
    if(num == 0){
        return "0";
    }
    int flag = num / abs(num);
    num = abs(num);

    char* res =  (char*)malloc(sizeof(char) * 11);//包括-最多也就10位
    memset(res,0,11);
    int pos = 0;
    while(num > 0){
        res[pos] = num % 7 + '0';
        pos++;
        num = num / 7;
    }
    if(flag < 0){
        res[pos]='-';
        pos++;
    }
    for(int j = 0; j < pos / 2; j++){
        char c = res[j];
        res[j] = res[pos - 1 - j];
        res[pos - 1 - j] = c;
    }
    res[pos] = '\0';
    return res;

}