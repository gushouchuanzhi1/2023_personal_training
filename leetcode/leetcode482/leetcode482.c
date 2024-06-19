char* licenseKeyFormatting(char* s, int k) {
    int length = 0;
    int len = strlen(s);
    char* save = (char*)malloc(sizeof(char) * (len + 1));
    save[len] = '\0';
    for(int i = 0; i < len; i++){
        save[i] = '-';
        if(s[i] != '-'){
            if(s[i] >= 'a' && s[i] <= 'z'){
                save[length] = toupper(s[i]);
                length++;
                continue;
            }
            save[length] = s[i];
            length++;
        }
    }
    if(length == 0){
        return "";
    }

    int signNumber = length / k - 1;
    if(length % k != 0){
        signNumber++;
    }
    //signNumber是要添加-的数量，length是总共的字符数量
    char* res = (char*)malloc(sizeof(char) * (length + signNumber + 1));
    res[length + signNumber] = '\0';
    int i = 0, j = 0;
    if(length % k != 0){
        for(i = 0; i < length + signNumber; i++){
            if((i + 1 + k - length % k) % (k + 1) == 0){
                res[i] = '-';
                continue;
            }
            res[i] = save[j];
            j++;
        }
    }
    if(length % k == 0){
        for(i = 0; i < length + signNumber; i++){
            if((i + 1) % (k + 1) == 0){
                res[i] = '-';
                continue;
            }
            res[i] = save[j];
            j++;
        }
    }
    free(save);
    return res;
}