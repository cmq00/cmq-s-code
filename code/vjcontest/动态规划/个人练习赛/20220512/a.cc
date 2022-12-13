#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
int a[N];

ll gcd(ll n,ll m)
{
    return m ? gcd(m,n % m):n;
}

void solve()
{
    int n;
    cin >> n;
    int t;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        t = gcd(a[i],t);
    }
    int ans = -1;
    for(int i = 1;i <= n;++i){
        if(a[i] == t){
            ans = a[i];
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}