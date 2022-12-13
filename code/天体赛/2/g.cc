
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 4;
const int inf = 1e9;
int cnt[N];

void solve()
{
    int n;
    cin >> n;
    int minx = inf;
    int maxx = -inf;
    for(int i = 1;i <= n;++i){
        int x;
        cin >> x;
        minx = min(minx,x);
        maxx = max(maxx,x);
        cnt[x]++;
    }
    cout << minx << " " << cnt[minx] << endl;
    cout << maxx << " " << cnt[maxx] << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}