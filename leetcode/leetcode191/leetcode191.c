int hammingWeight(int n) {
    long long int cnt = 0;
    long long int compareNum = 1;
    if(n & compareNum){
        cnt++;
    }
    for(int i = 1; i < 32; i++){
        compareNum = compareNum * 2;
        if(n & compareNum){
            cnt++;
        }
    }
    return cnt;
}