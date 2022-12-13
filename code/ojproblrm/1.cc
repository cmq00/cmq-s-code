#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fpow(ll base,ll pow)
{
    ll ans = 1;
    while(pow > 0){
        if(pow & 1){
            ans = base * ans;
        }
        pow >>= 1;
        base = base * base;
    }
    return ans;
}

int main()
{
    ll n,m;
    cin >> n >> m;
    cout << fpow(n,m) << endl;
    cout << pow(n,m) << endl;
    return 0;
}
