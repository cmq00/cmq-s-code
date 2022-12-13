#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    double n,m;
    cin >> n >> m;
    while(n--){
        double p;
        cin >> p;
        if(p < m)
           printf("On Sale! %.1lf\n",p);
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