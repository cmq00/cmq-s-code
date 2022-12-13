#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    double a,b;
    double x;
    cin >> a >> b;
    x = a / b;
    printf("%.0lf/%.1lf=%.0lf\n",a,x,b);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}