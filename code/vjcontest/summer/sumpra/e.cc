#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
int fa[N];

int find(int x)
{
    if(x == fa[x])
        return x;
    else
        return fa[x] = find(fa[x]);
}

void solve()
{
    int n,k;
    cin >> n >> k;
    int kk = k;
    int cnt = 0;
    for(int i = 0;i <= n;++i)
        fa[i]= i;
    while(k--){
        int x,y;
        cin >> x >> y;
        if(find(x) != find(y)){
            cnt++;
            fa[find(y)] = find(x);
        }
    }
    cout << kk - cnt << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}