bool isSubsequence(char* s, char* t) {
    int m = strlen(s), n = strlen(t);
    int i = 0, j = 0;
    while(i < m && j < n){
        if(s[i] == t[j]){
            i++;
        }
        j++;
    }
    return i == m;
}