int findLUSlength(char* a, char* b) {
    int m = strlen(a);
    int n = strlen(b);
    if(!strcmp(a,b)){
        return -1;
    }
    else{
        if(m>n)return m;
        else return n;
    }
}