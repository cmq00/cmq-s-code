#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 1e5 + 4;
vector<ll> x[N];
vector<ll> y[N];
int vis[N];

void solve()
{
    ll n,m;
    cin >> n >> m;
    ll maxx = -1,minx = N + 4;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            ll o;
            cin >> o;
            maxx = max(o,maxx);
            minx = min(o,minx);
            x[o].push_back(i);
            y[o].push_back(j);
            vis[o] = 1;            
        }
    }
    for(int i = minx;i <= maxx;++i){
        if(vis[i]){
            sort(x[i].begin(),x[i].end());
            sort(y[i].begin(),y[i].end());
        }
    }

    ll ans = 0;
    for(ll i = minx;i <= maxx;++i){
        //cout << x[i].size() << " " << y[i].size() << endl;
        //cout << x[i][x[i].size()] << endl;
        /*for(int k = 0;k < x[i].size();++k)
            cout << x[i][k] << " ";
        cout << endl;*/
        ll cnt = 1;
        ll tx = x[i][x[i].size() - 1],ty = y[i][y[i].size() - 1];
        //int tx = 0,ty = 0;
        if(!vis[i])
            continue;
        for(ll j = x[i].size() - 1;j >= 1;--j){
            ans += tx - x[i][j - 1] * cnt;  
            ans += ty - y[i][j - 1] * cnt;  
            cnt++;
            tx += x[i][j - 1];
            ty += y[i][j - 1];
        }
    }
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}