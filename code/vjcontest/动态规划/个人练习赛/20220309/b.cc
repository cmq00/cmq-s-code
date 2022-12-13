#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    ll a[604];
    for(int i = 3;i <= 600;++i){
        a[i] = i * (i - 1) + a[i - 1];
    }
    cout << a[n] << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}