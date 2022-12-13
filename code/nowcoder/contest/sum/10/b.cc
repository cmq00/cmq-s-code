#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e3 + 4;
ll a[N][N];

struct Node 
{
    int x,y;
};

vector<Node> v[N];

void solve()
{
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cin >> a[i][j];
            v[a[i][j]].push_back((Node){i,j});
        }
    }
    vector<int> res[N];
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            for(int k = 1;k <= m;++k){
                if(k == a[i][j])
                    continue;
                int mdis = 50000;
                for(int l = 0;l < v[k].size();++l){
                    mdis = min(mdis,abs(i - v[k][l].x) + abs(j - v[k][l].y));
                }
                res[a[i][j]].push_back(mdis);
            }
        }
    }
    int ans = 50000;
    for(int i = 1;i < m;++i){
        sort(res[i].begin(),res[i].end());
        ans = min(res[i][res[i].size() - 1],ans);
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