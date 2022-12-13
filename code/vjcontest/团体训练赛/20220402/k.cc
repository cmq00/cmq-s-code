#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 4;
int a[N];
int vis[N];

void solve()
{
    memset(vis,0,sizeof(vis));
    int n,m;
    cin >> n >> m;
    int num = 1;
    a[1] = 1;
    if(m < n){
        for(int i = 2;i <= n;++i){
            a[i] = a[i - 1] + m;
            if(a[i] > n){
                a[i] = ++num;
            }
        }
    }
    else{
        for(int i = 1;i <= n;++i)
            a[i] = i;
    }
    for(int i = 1;i <= n;++i){
        if(i == 1)
            cout << a[i];
        else
            cout << " " << a[i];

    }
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}