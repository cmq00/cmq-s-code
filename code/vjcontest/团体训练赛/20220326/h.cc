#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{   
    int n,k;
    cin >> n >> k;
    if(k == 1){
        puts("freesin");
        return ;
    }
    if(n - k >= k + 1){
        int a = ((n - k) / (k + 1)) * 2 + 2;
        int res =  n - (a / 2) * k - a / 2;
        if(res != 1)
            puts("pllj");
        else
            puts("freesin");
    }
    else{
        int a = n - k - 1;
        if(a == 1)
            puts("freesin");
        else
            puts("pllj");
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}