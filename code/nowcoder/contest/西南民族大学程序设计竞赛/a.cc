#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int main()
{
    int n;
    int bea[N],pri[N];
    scanf("%d",&n);
    for(int i = 1;i <= n - 1;++i)
        scanf("%d",&pri[i]);
    for(int i = 1;i <= n - 1;++i)
        scanf("%d",&bea[i]);

    long long ans = pri[1],maxx = bea[1];
    for(int i = 2;i <= n - 1;++i){
        if(i + 1 <= n - 1 && bea[i] > maxx){
            if(bea[i] < bea[i + 1])
                {ans += pri[i + 1];
                //printf("pri[%d]:%d\n",i + 1,pri[i + 1]);
                maxx = bea[i + 1];}
            else if(bea[i] > bea[i + 1])
                {ans += pri[i];
                //printf("pri[%d]:%d\n",i,pri[i]);
                maxx = bea[i];}
            else   
                {ans += min(pri[i],pri[i + 1]);
                //printf("pri[%d]:%d\n",i + 1,pri[i + 1]);
                maxx = bea[i];}
            i++;
        }
        else if(i + 1 > n - 1 && bea[i] > maxx){
            ans += pri[i];
            //printf("pri[%d]:%d\n",i,pri[i]);
        }
    }
    printf("%lld\n",ans);
    return 0;

}