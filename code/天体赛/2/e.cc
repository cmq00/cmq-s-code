#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int a[100];
    for(int i = 0;i < 24;++i)
        cin >> a[i];
    int t;
    while(cin >> t && t >= 0 && t <= 23){
        cout << a[t] << " ";
        if(a[t] > 50){
            puts("Yes");
        }
        else
            puts("No");
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