bool isValid(char* s) {
    int length = strlen(s);
    char* stack = (char*)malloc(sizeof(char) * (length + 1));
    int top = -1; // 栈顶指针初始化为-1
    
    for(int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i]; // 进栈
        } else {
            if (top == -1) { // 如果栈为空，直接返回false
                free(stack);
                return false;
            }
            if (s[i] == ')' && stack[top] != '(') {
                free(stack);
                return false;
            }
            if (s[i] == ']' && stack[top] != '[') {
                free(stack);
                return false;
            }
            if (s[i] == '}' && stack[top] != '{') {
                free(stack);
                return false;
            }
            top--; // 出栈
        }
    }
    
    bool flag = (top == -1); // 如果栈为空，返回true，否则返回false
    free(stack);
    return flag;
}