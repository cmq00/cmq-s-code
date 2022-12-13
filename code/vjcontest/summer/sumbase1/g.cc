#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e6 + 4;
ll a[N];
vector<int> v[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i){
        for(int j = i;j <= n;++j){
            if(a[j] < a[i])
                v[i].push_back(j);
        }
    }
    // for(int i = 1;i <= n;++i){
    //     cout << a[i] << " ";
    //     if(!v[a[i]].empty()){
    //         for(int j = 0;j < v[a[i]].size();++j)
    //             cout << v[a[i]][j] << " ";
    //         cout << endl;
    //     }
    // }
    ll ans = 0;
    for(int i = 1;i <= n;++i){
        if(v[i].empty())
            continue;
        for(int j = 0;j < v[i].size();++j){
            int x = v[i][j];
            if(!v[x].empty()){
                ans += v[x].size();
            }
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