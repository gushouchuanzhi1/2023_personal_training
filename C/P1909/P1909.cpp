#include <stdio.h>

int main(){
    int n,pencil[3][2];
    scanf("%d",&n);
    for(int i = 0; i<3;i++){
        //读取一下
        scanf("%d %d",&pencil[i][0],&pencil[i][1]);
    }
    int min[3] = {0};
    int result=0;
    for(int j=0; j<3;j++){
        if(n%pencil[j][0]>0){
            min[j] = (n/pencil[j][0]+1)*pencil[j][1];
        }
        else min[j] = n/pencil[j][0]*pencil[j][1];
    }
    result=min[0];
    for(int m=1;m<3;m++){
        result>=min[m]?result=min[m]:result=result;
    }
    printf("%d",result);
}