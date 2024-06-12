int calculateLength(int start1, int start2, int duration) {
    if (start1 + duration - 1 >= start2) {
        return start2 - start1;
    }
    else {
        return duration;
    }
}

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    //timeSeriesSize是数组的长度
    //duration是中毒的时间
    long long time = 0;
    for (int i = 0; i < timeSeriesSize - 1; ++i) {
        time += calculateLength(timeSeries[i], timeSeries[i + 1], duration);
    }
    return time + duration;
}