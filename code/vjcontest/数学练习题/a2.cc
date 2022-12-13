#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e7;

ll vis[N + 4];
ll p[N + 4],f[N + 4];

ll fpow(ll n,ll pow)
{
    ll ans = 1;
    while(pow > 0){
        if(pow & 1)
            ans = ans * n;
        pow >>= 1;
        n = n * n;
    }
    return ans;
}

int main()
{
    
   
    int m = 0;
    for(int i = 2;i <= N;++i){
        if(vis[i] == 0){
            vis[i] = i;
            f[i] = 1;
            p[++m] = i;
        }
        for(int j = 1;j <= m;++j){
            if(p[j] > vis[i] || p[j] > N / i)
                break;
            vis[i * p[j]] = p[j];
            if(vis[i] == p[j])
                f[i * p[j]] = f[i];
            else
                f[i * p[j]] = f[i] + 1; 
        }
    }
    
    /*int cnt = 0;
     for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            p[cnt++] = i;
            f[i] = 1;
        }
        for (int j = 0; j < cnt && i * p[j] <= N; j++)
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                f[i * p[j]] = f[i];
                break;
            }
            f[i * p[j]] = f[i] + 1;
        }
    }*/

    int t;
    scanf("%d",&t);
    while(t--){
        ll c,d,x,ans = 0;
        scanf("%lld %lld %lld",&c,&d,&x);
        for(int i = 1;i <= sqrt(x);++i){
            if(x % i == 0){
                if((x / i + d) % c == 0){
                    ll a = (x / i + d) / c;
                    ans += fpow(2,f[a]);
                }
            
                if(i != x / i){
                    ll g = x / i;
                    if((x / g + d) % c == 0){
                        ll a = (x / g + d) / c;
                        ans += fpow(2,f[a]);
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}