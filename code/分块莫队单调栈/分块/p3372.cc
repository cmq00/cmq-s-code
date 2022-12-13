#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 4;
ll a[N],id[N],sum[N],b[N];//id[i] 存每个位置的块号，sum[i] 存每个块的区间和，b[i]更新完整的块
ll n,q,len;

void add(int l,int r,ll x)
{
    ll st = id[l],en = id[r];
    if(st == en){
        for(int i = l;i <= r;++i)
            a[i] += x,sum[st] += x;
        return ;
    }
    for(int i = l;id[i] == st;++i)
        a[i] += x,sum[st] += x;
    for(int i = st + 1;i < en;++i)
        b[i] += x,sum[i] += len * x;
    for(int i = r;id[i] == en;--i)
        a[i] += x,sum[en] += x;
    return ;
}

ll query(int l,int r)
{
    ll st = id[l],en = id[r];
    ll ans = 0;
    if(st == en){
        for(int i = l;i <= r;++i)
            ans = ans + a[i] + b[st];
        return ans;
    }
    for(int i = l;id[i] == st;++i)
        ans = ans + a[i] + b[st];
    for(int i = st + 1;i < en;++i)
        ans += sum[i];
    for(int i = r;id[i] == en;--i)
        ans = ans + a[i] + b[en];
    return ans;
}

int main()
{
    scanf("%lld %lld",&n,&q);
    len = sqrt(n);
    for(int i = 1;i <= n;++i){
        scanf("%lld",&a[i]);
        id[i] = (i - 1) / len + 1;
        sum[id[i]] += a[i];
    }
    while(q--){
        int op;
        scanf("%d",&op);
        if(op == 1){
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            add(l,r,x);
            /*for(int i = 1;i <= n;++i)
                printf("%lld ",a[i]);
            printf("\n");*/
        }
        else{
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%lld\n",query(l,r));
        }
    }
    return 0;
}
