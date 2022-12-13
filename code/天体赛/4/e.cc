#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    int sc[200];;
    int ans[200];
    for(int i = 1;i <= m;++i)
        cin >> sc[i];
    for(int i = 1;i <= m;++i)
        cin >> ans[i];
    while(n--){
        int res = 0;
        for(int i = 1;i <= m;++i){
            int x;
            cin >> x;
            if(x == ans[i])
                res += sc[i];
        }
        cout << res << endl;
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}