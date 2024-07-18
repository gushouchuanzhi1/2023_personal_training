int maxProfit(int* prices, int pricesSize) {
    int ret = 0;
    for(int i = 0; i < pricesSize - 1; i++){
        int dif = prices[i+1] - prices[i];
        if(dif > 0){
            ret += dif;
        }
    }
    return ret;
}