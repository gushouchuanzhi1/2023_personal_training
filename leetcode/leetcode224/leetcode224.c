int calculate(char* s) {
    int n = strlen(s);
    int ops[n], top = 0;
    int sign = 1;
    ops[top++] = sign;

    int ret = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            i++;
        } else if (s[i] == '+') {
            sign = ops[top - 1];
            i++;
        } else if (s[i] == '-') {
            sign = -ops[top - 1];
            i++;
        } else if (s[i] == '(') {
            ops[top++] = sign;
            i++;
        } else if (s[i] == ')') {
            top--;
            i++;
        } else {
            long num = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            ret += sign * num;
        }
    }
    return ret;
}
