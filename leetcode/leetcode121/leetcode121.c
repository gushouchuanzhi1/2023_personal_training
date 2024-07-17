int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxprofit = 0;
    for(int i = 0; i < pricesSize; i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
            continue;
        }
        if(prices[i] - minPrice > maxprofit){
            maxprofit = prices[i] - minPrice;
            continue;
        }
    }
    return maxprofit;
}