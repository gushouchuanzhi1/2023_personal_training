int evalRPN(char** tokens, int tokensSize) {
    int* stack = (int*)malloc(sizeof(int) * tokensSize);
    int length = 0;
    
    for (int i = 0; i < tokensSize; i++) {
        char* temp = tokens[i];
        if (strlen(temp) > 1 || isdigit(temp[0]) || (temp[0] == '-' && strlen(temp) > 1)) {
            stack[length] = atoi(temp);
            length++;
        } else {
            int a = stack[length - 1];
            length--;
            int b = stack[length - 1];
            length--;
            int result = 0;
            
            if (temp[0] == '+') {
                result = b + a;
            } else if (temp[0] == '-') {
                result = b - a;
            } else if (temp[0] == '*') {
                result = b * a;
            } else if (temp[0] == '/') {
                result = b / a;
            }
            
            stack[length] = result;
            length++;
        }
    }
    
    int finalResult = stack[length - 1];
    free(stack);
    return finalResult;
}