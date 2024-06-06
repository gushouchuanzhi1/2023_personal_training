#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

int note[62505];
int index = 0; // ���ڸ���note�����еĵ�ǰλ��  

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
    int charsInLine = 0; // ���ڸ��ٵ�ǰ���Ѷ�ȡ���ַ���  
    while (1) {
        if (scanf(" %c", &c) != 1) { // ע��ո����������հ��ַ��������ո�ͻ��з���  
            break; // �����ȡʧ�ܣ����磬�����ļ�ĩβ�������˳�ѭ��  
        }
        if (c == 'E') {
            note[index++] = 0; // ����'E'����ʾ������������0����note����  
            break; // �˳�ѭ��  
        }
        if (c == 'W') {
            note[index++] = 1;
        }
        else if (c == 'L') {
            note[index++] = 2;
        }
        charsInLine++;
        if (charsInLine == 25) {
            charsInLine = 0; // ���ü�������Ϊ��һ����׼��  
            // �������ѡ���Ե����һ��scanf����ȡ���������з�����ͨ������Ҫ����Ϊ%c��ʽ˵�����������հ��ַ�  
        }
    }
    // ȷ��û�г����������  
    if (index > 62505) {
        fprintf(stderr, "Error: Input exceeds array size.\n");
        return 1;
    }
    // ����11����  
    Judge(note, 11);
    printf("\n");
    // ����21����  
    Judge(note, 21);
    return 0;
}