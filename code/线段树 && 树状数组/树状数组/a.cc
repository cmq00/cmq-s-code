//单点修改，区间查询
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6 + 4;
ll a[N],c[N],n,q;

int lowbit(int x)
{
    return x & (-x);
}

void add(ll x,ll k)
{
    while(x <= n){
        c[x] += k;
        x += lowbit(x);
    }
}

ll query(int x)
{
    ll ans = 0;
    while(x>=1){
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        add(i,a[i]);
    }
    while(q--){
        int op,l,r,x,k;
        cin >> op;
        if(op == 1){
            cin >> x >> k;
            add(x,k);
        }
        else{
            cin>>l>>r;
            cout<<query(r) - query(l - 1)<<endl;
        }
    }
    return 0;
}