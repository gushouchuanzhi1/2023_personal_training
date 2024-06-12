int getReNumber(char* num){
    int length = strlen(num);
    int res = 0, flag = 1;//最后的结果，统计有多少位，正负
    for(int i = 0; i < length; i++){
        if(num[i] == '-'){
            flag = -1;
            continue;
        }
        if(num[i] >= '0' && num[i]<='9'){
            res = res * 10 + (num[i] - '0');
            continue;
        }
        if(num[i] == '+'){
            break;
        }
    }
    return res * flag;
}

int getImNumber(char* num){
    int length = strlen(num);
    int res = 0, flag = 1;
    int i = 1;
    while(num[i] != '+'){
        ++i;
    }
    for(++i;i<length;i++){
        if(num[i] == '-'){
            flag = -1;
            continue;
        }
        if(num[i] >= '0' && num[i]<='9'){
            res = res * 10 + (num[i] - '0');
            continue;
        }
        if(num[i] == 'i'){
            break;
        }
    }
    return res * flag;
}

char* complexNumberMultiply(char* num1, char* num2) {
    int real1 = getReNumber(num1);
    int imag1 = getImNumber(num1);
    int real2 = getReNumber(num2);
    int imag2 = getImNumber(num2);
    char * res = (char *)malloc(sizeof(char) * 20);
    snprintf(res, 20, "%d+%di", real1 * real2 - imag1 * imag2, real1 * imag2 + imag1 * real2);
    return res;
}