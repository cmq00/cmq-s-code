#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;
int a[N],maxx[N],minx[N];
long long sum[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){
        scanf("%d",&a[i]);
        sum[i] = sum[i - 1] + a[i];
    }   
    stack<int> s;
    for(int i = n;i >= 1;--i){
        while(!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if(s.empty())
            maxx[i] = n + 1;
        else
            maxx[i] = s.top();
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    for(int i = 1;i <= n;++i){
        while(!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if(s.empty())
            minx[i] = 0;
        else
            minx[i] = s.top();
        s.push(i);
    }
    /*for(int i = 1;i <= n;++i)
        printf("%d ",maxx[i]);
    printf("\n");
     for(int i = 1;i <= n;++i)
        printf("%d ",minx[i]);
    printf("\n");*/

    long long ans = 0;
    for(int i = 1;i <= n;++i){
        long long res = a[i] * (sum[maxx[i] - 1] - sum[minx[i]]);
        ans = max(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}