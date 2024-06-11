int abs_dif(int a, int b) {
    return a - b > 0 ? a - b : b - a;
}

int cal(char* time1, char* time2) {
    //HH:MM HH:MM
    //将所有的小时都化为分钟
    int hour1 = (time1[0] - '0') * 10 + (time1[1] - '0');
    int min1 = (time1[3] - '0') * 10 + (time1[4] - '0');
    int res1 = 60 * hour1 + min1;

    int hour2 = (time2[0] - '0') * 10 + (time2[1] - '0');
    int min2 = (time2[3] - '0') * 10 + (time2[4] - '0');
    int res2 = 60 * hour2 + min2;

    int res = abs_dif(res1, res2);
    if (res <= 720) return res;
    return 1440 - res;
}

int findMinDifference(char** timePoints, int timePointsSize) {
    int res = cal(timePoints[0], timePoints[1]);
    for (int i = 0; i < timePointsSize - 1; i++) {
        for (int j = i + 1; j < timePointsSize; j++) {
            int diff = cal(timePoints[i], timePoints[j]);
            if (res > diff) {
                res = diff;
            }
        }
    }
    return res;


}