#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5;
bool vis[N + 4],p[N + 4],f[N + 4];

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
    /*ll v[N],prime[N],D[N];
    fill(v,v + N,0);
    int m = 0,n = N - 1;
    for(int i = 2;i <= n;++i){
        if(v[i] == 0){
            v[i] = i;
            D[i] = 1;
            prime[++m] = i;
        }
        for(int j = 1;j <= m;++j){
            if(prime[j] > v[i] || prime[j] > N / i)
                break;
            v[i * prime[j]] = prime[j];
            if(v[i] == prime[j])
                D[i * prime[j]] = D[i];
            else
                D[i * prime[j]] = D[i] + 1; 
        }
    }*/
    /*cout << fpow(2,0) << endl;
    int x;
    while(cin >> x)
        cout << D[x] << endl;
    return 0;*/
    int cnt = 0;
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
    }
    cout << f[6] << endl;
    int t;
    scanf("%d",&t);
    while(t--){
        ll c,d,x,ans = 0;
        scanf("%lld %lld %lld",&c,&d,&x);
        for(int i = 1;i <= sqrt(x);++i){
            if(x % i == 0){
                printf("i1:%d\n",i);
                printf("x:%lld i1:%d d:%lld c:%lld\n",x,i,d,c);
                printf("(x / i + d) / c:%lld\n",(x / i + d) / c);
                if((x / i + d) % c == 0){
                    printf("i2:%d\n",i);
                    ll a = (x / i + d) / c;
                    printf("fpow(2,D[%lld]:%lld\n",a,fpow(2,f[a]));
                    ans += fpow(2,f[a]);
                }
            
                if(i != x / i){
                    ll g = x / i;
                    printf("g1:%lld\n",g);
                    if((x / g + d) % c == 0){
                         printf("g2:%lld\n",g);
                        ll a = (x / g + d) / c;
                        printf("fpow(2,D[%lld]:%lld\n",a,fpow(2,f[a]));
                        ans += fpow(2,f[a]);
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}