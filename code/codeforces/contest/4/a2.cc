#include <bits/stdc++.h>

using namespace std;

int bin[33],a[104],cnt0[33],cnt1[33];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(bin,0,sizeof(bin));
        memset(cnt0,0,sizeof(cnt0));
           memset(cnt1,0,sizeof(cnt1));
        int n,t;
        scanf("%d %d",&n,&t);
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        for(int j = 0;j <= 30;++j){
            for(int i = 0;i < n;++i){
                int x = (a[i] >> j) & 1;
                //printf("x:%d\n",x);

                if(x == 0)
                    cnt0[j]++;
                else
                    cnt1[j]++;
            }
        }
        /*for(int i = 0;i <= 30;++i)
            printf("%d",cnt0[1]);
        printf("\n");
        for(int i = 0;i <= 30;++i)
            printf("%d",cnt1[1]);
        printf("\n");*/

        int ans = 0;
        for(int i = 0;i <= 30;++i){
            if(cnt1[i] > cnt0[i] && ans + pow(2,i) <= pow(2,t) - 1)
                ans += pow(2,i);
        }
        printf("%d\n",ans);
    }
    return 0;
}