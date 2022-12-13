#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
const int INF = 2147483647;
int h[N],f[N];

void solve()
{
    int n = 0;
    while(~scanf("%d",&h[++n]));
    --n;
    // cin >> n;
    // for(int i = 1;i <= n;++i){
    //     cin >> h[i];
    // }
    int t;
    t = 0;
    memset(f,0,sizeof(f)),f[0]=INF;
    for(int i = 1;i <= n;++i){
        int l,r,m;
        l = 0,r = t + 1;
        while(r - l > 1){
            //cout << l << " " << r << " " << m << endl;
            m = (r + l) >> 1;
            if(f[m] >= h[i])
                l = m;
            else
                r = m;
        }
        if(l + 1 > t)
            t = l + 1;
        f[l + 1] = h[i];
    }
    printf("%d\n",t);
    t = 0;
    memset(f,0,sizeof(f)),f[0]=INF;
    for(int i = 1;i <= n;++i){
        int l,r,m;
        l = 0,r = t + 1;
        while(r - l > 1){
            m = (r + l) >> 1;
            if(f[m] < h[i])
                l = m;
            else
                r = m;
        }
        if(l + 1 > t)
            t = l + 1;
        f[l + 1] = h[i];
    }
    printf("%d\n",t);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}