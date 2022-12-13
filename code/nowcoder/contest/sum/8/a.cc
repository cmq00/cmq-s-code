#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 100004;
int a[N];
int cnt[N];

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    ll ans = 0;
    int pos = 0;
    set<int> s;
    for(int i = 1;i <= n;++i){
        s.insert(a[i]);
        cnt[a[i]]++;
        if(s.size() == m){
            pos = i;
            break;
        }
    }
    bool f = 0;
    if(pos){
        ans += n - pos + 1; 
        f = 1;
    }
    else{
         puts("0");
         return ;
    }
    //cout << pos << endl;
    int l = 1,r = pos,t = 0;
    for(;r <= n && l <= r;){
        if(f){
            t = a[l];
            cnt[a[l]]--;
            l++;
            if(cnt[t])
                ans += n - r + 1;
            else    
                f = 0;
        }
        else{
            r++;
            if(r > n)
                break;
            cnt[a[r]]++;
            if(cnt[t]){
                ans += n - r + 1;
                f = 1;
            }
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