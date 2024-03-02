    #include <iostream>
    #include <stdio.h>
    #include <algorithm>
    using namespace std;
    int n,m,x,ans,l,r,a[1005],b[1005];
    int main()
    {
        cin>>m>>n;
        l=0;r=0;
        for (int i=1;i<=n;i++)
         {
             scanf("%d",&x);
             if (a[x]==0) 
             {
                ans++;
                r++;b[r]=x;
                a[x]=1;
                if (r>m) {l++;a[b[l]]=0;}
             }
         }
        printf("%d\n",ans);
        return 0;
}


