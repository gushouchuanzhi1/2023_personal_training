#include <stdio.h>

char* solveEquation(char* equation) {
    int factor = 0, value = 0;//x的系数和常量都为0
    int i = 0, n = strlen(equation), sign1 = 1;//左侧读到系数都是默认乘1，右侧为-1，因为要移向
    while(i < n){
        if(equation[i] == '='){
            //当读到等号，即为右边了，sign系数变化
            sign1 = -1;
            i++;
            continue;
        }
        int sign2 = sign1, number = 0;
        bool valid = false;//用于判断x之前的系数为1或者为别的
        if(equation[i]=='-'||equation[i]=='+'){
            sign2 = (equation[i] == '-')?-sign1:sign1;//当前的系数是正还是负
            i++;
        }
        while(i<n&&equation[i]>='0'&&equation[i]<='9'){
            number = number *10 + (equation[i] - '0');
            i++;
            valid=true;//这里读到这个数字对于x来说不是等于1的，也就是说没有被省略掉
        }
        if(i < n && equation[i] == 'x'){
            factor += valid?sign2*number:sign2;//如果前面有数字就作为系数，如果没有数字就是-x或者x
            i++;
        }
        else{
            value += sign2*number;
        }
    }
    if(factor ==0){
        return (value==0)?"Infinite solutions":"No solution";
    }
    char*ans = (char * )malloc(sizeof(char)*40);
    sprintf(ans,"x=%d",-value/factor);//因为value和x在一边，移到等式左边有-1
    return ans;

}