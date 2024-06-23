bool isPowerOfTwo(int n) {
    if(n <= 0) return false; 
    while(n > 0){
        if(n == 1) return true;
        if(n % 2 == 1) return false;
        n = n / 2;
    }
    return true;
}


//如果使用不循环和不递归来计算这个数的幂，可以使用位运算。
//对于所有的2的次方的数，一定是如100000，1000，100000等二进制形式
//所以我们使用n & (n -1)来进行计算，如果按位与的结果是0000，那么就可以判断是符合要求的

bool isPowerOfTwo(int n){
    return (n > 0) && (n & (n - 1)) == 0;
}


