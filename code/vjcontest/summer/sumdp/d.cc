#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e5 + 4;

struct Node 
{
    ll x,y;
}a[N];
ll dp[N];

bool cmp(Node a,Node b)
{
    //if(a.x == b.x)
        return a.y < b.y;
    //return a.x < b.x;
}

void solve()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){
        scanf("%lld %lld",&a[i].x,&a[i].y);
    }
    sort(a + 1,a + 1 + n,cmp);
    ll ans = 0;
    for(int i = 1;i <= n;++i){
        if(a[i].x > a[i - 1].y){
            dp[i] = dp[i - 1] + a[i].y - a[i].x + 1;
        }
        else{
            int l = 1,r = i - 1,mid = 0,t = 0;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(a[mid].y < a[i].x)
                    l = mid;
                else    
                    r = mid - 1;
            }
            if(a[l].y >= a[i].x)
                l -= 1;
            dp[i] = max(dp[i - 1],dp[l] + a[i].y - a[i].x + 1);
        }
        ans = max(ans,dp[i]);
    }
    printf("%lld\n",ans);
}

int main()//https://www.luogu.com.cn/problem/P1868
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}