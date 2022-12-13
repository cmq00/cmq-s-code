#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
ll a[N];
int l[N],r[N];
bool vis[N];

void solve()
{
    memset(vis,1,sizeof(vis));
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        l[i] = i - 1;
        r[i] = i + 1;
    }
    l[1] = n;
    r[n] = 1;
    int ans = 0;
    for(int i = 1;i <= n;++i){
        // cout << i << endl;
        // cout << a[l[i]] << " " << a[i] << " " << a[r[i]] << endl;
        // cout << l[i] << " " << i << " " << r[i] << endl;
        if(l[i] == i || r[i] == i)
            continue;
        if((a[i] == a[r[i]] || a[i] + a[r[i]] == k) && (vis[i] && vis[r[i]])){
            ans++;
            int x = r[r[i]];
            l[x] = l[i];
            r[l[i]] = x;
            //i = l[i];
            vis[i] = 0;
            vis[r[i]] = 0;
            //cout << "!" << endl;
        }
        if((a[i] == a[l[i]] || a[i] + a[l[i]] == k) && (vis[i] && vis[l[i]])){
            ans++;
            int x = l[l[i]];
            r[x] = r[i];
            l[r[i]] = x;
            //i = r[i];
            vis[i] = 0;
            vis[l[i]] = 0;
            //cout << "!" << endl;
        }
    }
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}