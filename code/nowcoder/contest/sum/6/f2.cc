#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    stack<ll> s;
    ll n,k,ans = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;++i){
        ll x;
        cin >> x;
        if(!s.empty()){
            if(s.top() + x == k || s.top() == x){
                s.pop();
                ans++;
            }
            else
                s.push(x);
        }
        else    
            s.push(x);
    }
    vector<ll> v;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    int l = 0,r = v.size() - 1;
    while(l < r && (v[l] == v[r] || v[l] + v[r] == k)){
        ans++;
        l++;
        r--;
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