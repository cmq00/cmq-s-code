#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;

const int mod = 10000;

void solve()
{
    stack<ll> s;
    bool f = 0;
    for(int i = 1;;++i){
        if(i % 2){
            ll x;
            cin >> x;
            //cout << x << endl;
            if(f == 0)
                s.push(x);
            else{
                ll res = s.top();
                ll ans = (res % mod * x % mod) % mod;
                s.pop();
                s.push(ans);  
            }
        }
        else{
            char ch;
            scanf("%c",&ch);
            if(ch == '\n')
                break;
            if(ch == '*'){
                f = 1;
            }
            else    
                f = 0;
        }
    }
    ll sum = 0;
    while(!s.empty()){
        int x = s.top();
        sum = (sum + x) % mod;
        s.pop();
    }
    cout << sum << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}