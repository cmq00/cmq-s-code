#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main()
{   
    ios_base::sync_with_stdio(0);
    ll n,m,q;
    cin >> n >> m;
    if(n - m > 1)
        n = m + 1;
    ll maxx = 0;
    ll h = m + 1;
    for(int i = 1;i <= n;++i)
        maxx += h,h++;

        cout << maxx << endl;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        if(x > maxx)
            cout << "NO"<< endl;
        else
            cout <<"YES"<< endl;
    }
    return 0;

}