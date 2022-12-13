#include <bits/stdc++.h>

using namespace std;
int pos;
bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        int ans = 0;
        scanf("%d %d %d",&a,&b,&c);
        int va[10004],vb[10004];
        int suma[10004],sumb[10004];
        memset(suma,0,sizeof(suma));
         memset(sumb,0,sizeof(sumb));
        for(int i = 1;i <= a;++i)
            scanf("%d",&va[i]);
        for(int i = 1;i <= b;++i)
            scanf("%d",&vb[i]);
        if(a + min(c / 2,b) < c)
            ans = -1;
        else{
            sort(va + 1,va + 1 + a,cmp);
            sort(vb + 1,vb + 1 + b,cmp);
            /*for(int i = 1;i <= a;++i)
                printf("%d ",va[i]);
            printf("\n");
            for(int i = 1;i <= b;++i)
                printf("%d ",vb[i]);
            printf("\n");*/
            
           suma[0] = sumb[0] = 0;

            for(int i = 1;i <= a;++i)
                suma[i] += suma[i - 1] + va[i];
            for(int i = 1;i <= b;++i)
                sumb[i] += sumb[i - 1] + vb[i]; 
            /*for(int i = 1;i <= a;++i)
                printf("%d ",suma[i]);
            printf("\n");
            for(int i = 1;i <= b;++i)
                printf("%d ",sumb[i]);
            printf("\n");*/
            
            for(int i = 1;i <= a;++i){
                if(i < c - i || c - i > b)
                    continue;
                ans = max(ans,suma[i] + sumb[c - i]);
                /*if(suma[i] + sumb[c - i] >= ans){
                    ans = suma[i] + sumb[c - i];
                    pos = i;
                }*/
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}