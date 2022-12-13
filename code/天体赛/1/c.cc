#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int x;
    cin >> x;
    if(x >= 90)
        printf("gong xi ni kao le %d fen!\n",x);
    else
        printf("kao le %d fen bie xie qi!\n",x);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}