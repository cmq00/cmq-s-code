#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[200];
    int ans1 = 0,ans2 = 0;
    for(int i = 1;i <= n;++i){
        int x;
        cin >> x;
        if(x % 2)
            ans1++;
        else
            ans2++;
    }
    cout << ans1 << " " << ans2 << endl;
    
}   

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}