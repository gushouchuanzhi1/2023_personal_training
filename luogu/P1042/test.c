#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

int note[62505];
int index = 0; // 用于跟踪note数组中的当前位置  

void Judge(int note[], int rule)
{
    int w = 0, l = 0;
    for (int i = 0; 1; i++)
    {
        if (note[i] == 1)
        {
            w++;
        }
        if (note[i] == 2)
        {
            l++;
        }
        if (note[i] == 0)
        {
            printf("%d:%d\n", w, l);
            break;
        }
        if (w - l >= 2 || l - w >= 2)
        {
            if (w >= rule || l >= rule)
            {
                printf("%d:%d\n", w, l);
                w = 0;
                l = 0;
            }
        }
    }
}

int main() {
    char c;
    int charsInLine = 0; // 用于跟踪当前行已读取的字符数  
    while (1) {
        if (scanf(" %c", &c) != 1) { // 注意空格，它会跳过空白字符（包括空格和换行符）  
            break; // 如果读取失败（例如，到达文件末尾），则退出循环  
        }
        if (c == 'E') {
            note[index++] = 0; // 遇到'E'，表示比赛结束，将0存入note数组  
            break; // 退出循环  
        }
        if (c == 'W') {
            note[index++] = 1;
        }
        else if (c == 'L') {
            note[index++] = 2;
        }
        charsInLine++;
        if (charsInLine == 25) {
            charsInLine = 0; // 重置计数器，为下一行做准备  
            // 这里可以选择性地添加一个scanf来读取并丢弃换行符，但通常不需要，因为%c格式说明符会跳过空白字符  
        }
    }
    // 确保没有超出数组界限  
    if (index > 62505) {
        fprintf(stderr, "Error: Input exceeds array size.\n");
        return 1;
    }
    // 对于11分制  
    Judge(note, 11);
    printf("\n");
    // 对于21分制  
    Judge(note, 21);
    return 0;
}