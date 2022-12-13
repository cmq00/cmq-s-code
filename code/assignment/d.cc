#include <bits/stdc++.h>

using namespace std;

int fun(int a[],int m)
{
    int i,add,maxx = 0;
    for(i = 1;i < m;++i){
        add = a[i] - i + 1;
        if(add > 0 && add > maxx)
            maxx = add;
    }
    return a[0] + maxx + 1;
}
    
int main()
{
    int i,m,t,a[100000],ans[100000];
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int p = n;
        while(n--){
            scanf("%d",&m);
            for(i = 0;i < m;++i)
                scanf("%d",&a[i]);
            ans[n] = fun(a,m);
        }
        sort(ans,ans + p);
        
        //for(i = 0;i < p;++i)
           //printf("%d ",ans[i]);
       // printf("\n");
        
        printf("%d\n",ans[0]);
    }
    return 0;
}
        
    
