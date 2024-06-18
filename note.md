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

leetcode521:最长特殊序列Ⅰ
没什么好说的，脑袋抽了，直接使用了strcmp，来判断字符串，这里是逐个字符比较大小，返回的是当前比较到的字符ascil码大小关系。

leetcode524:
思路
和leetcode392很像，先找到符合要求的字符串，然后比较他们谁的长度最长，对于长度一样的使用strcmp就可以比较字典序的大小了。
解题方法
初次看到这个题目，和leetcode的392题目很像，将一个字符串换成了多个字符串，所以就把他当稍微复杂一点的392题做了，结果发现报错了。因为第一遍的代码自己没有处理字典序的问题，所以导致对于"abe"和"abc"应该返回后者，但是我返回了前者。
这里我们首先把leetcode392题的代码敲进去，写成check函数，可见下方代码。然后就是一个简单的比较符合check函数字符串的长度以及相关条件的代码。在对代码多次分析修改之后，发现只要在对于符合check要求的字符串比较时规定以下的规则：①优先转换为更长的符合要求字符串②如果字符串长度一样，那么直接在这里使用strcmp比较字典序就可以了。

