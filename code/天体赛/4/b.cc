#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    double a,b;
    cin >> a >> b;
    double ans;
    ans = a * b /10;
    printf("%.2lf\n",ans);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}