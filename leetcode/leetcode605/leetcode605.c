bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int cnt = 0, left = -1;
    for(int i = 0; i < flowerbedSize; i++){
        if(flowerbed[i] == 1){
            if(left == -1){
                cnt = cnt + i / 2;
            }
            else{
                cnt = cnt + (i - left - 2) / 2;
            }
            left = i;//更新一下这个连续区间
        }
    }
    //结束之后看最后有没有连续的区间
    if(left == -1){
        cnt += (flowerbedSize + 1) / 2;
    }
    else{
        cnt += (flowerbedSize - left - 1) / 2;
    }
    if(cnt >= n) return true;
    return false;
}