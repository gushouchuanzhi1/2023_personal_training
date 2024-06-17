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

leetcode640:
①这里对这个方程分析有两处需要注意的地方，一是对方程左右两边的数据处理，通过左边默认系数1，右侧默认系数-1来实现
第二是对x前的系数来分析，由于x前的是被省略的，所以我们在读取数字的时候可以通过判断是否有数字，即程序中的valid值来判断x的系数

leetcode557：
①我们对字符串进行空间分配的时候需要在已知的length上+1，这不仅可以作为安全的容量，并且还要作为字符串结束的表示'\0'放置的位置
②本题需要对字符串里的每个单词部分进行反转，这里可以通过维护i，start，p三个变量来实现，i用于记录在整个大的字符串中遍历到的位置
start等于i的位置，如果后续读到的不是空格那么就继续对i自增，start不动，当读到空格就开始遍历当前这个单词即可。

leetcode392:
采用双指针同时遍历目标字符串和原字符串，判断结束的标志是如果子字符串在原字符串找到了，那么才移动子字符串的指针，最后判别子字符串的指针是否到达最后一位即可。


