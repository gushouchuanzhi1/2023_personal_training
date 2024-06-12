leetcode537:
①初始化字符串：char * res = (char *)malloc(sizeof(char) * 20);
这里res是字符串的指针，指向字符串第一个字符，这个字符串是最多有20个char字符，所以使用malloc为其分配空间
然后使用(char *)将其强制转换成char的指针类型
②官方题解：
bool parseComplexNumber(const char * num, int * real, int * image) {
    char *token = strtok(num, "+");
    *real = atoi(token);
    token = strtok(NULL, "i");
    *image = atoi(token);
    return true;
};
这里的strtok函数char *strtok(char s[], const char *delim);传入一个字符串和字符用于分割字符串
int atoi (const char * str);可以将扫描这个字符串，然后将遇到的数字（包括正负号）转换为整型变量

leetcode592:
①辗转相除法来求最大公约数
long long gcd(long long a, long long b) {
    long remainder = a % b;
    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }
    return b;
}
如何求最小公倍数？a*b/c即为最小公倍数，不过需要先求出最大公约数。
