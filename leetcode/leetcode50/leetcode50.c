double myPow(double x, int n) {
    int i=n;
    double y=1;
    if(n==0||x==1)
    return 1;
    while(n!=0)
    {
        if(n==1||n==-1)
            break;
        if(n%2!=0)
            y=x*y; 
        x=x*x;    
        n/=2;
    }
    return i<0? 1/(x*y):x*y;
}