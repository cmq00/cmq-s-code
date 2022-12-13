#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e6 + 4;

struct Node
{
    int l,r;
}a[N];

bool cmp(Node a,Node b)
{
    if(a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1,a + 1 + n,cmp);
    int ans = 0;
    int nowl = 0,nowr = 0;
    for(int i = 1;i <= n;++i){
        if(a[i].l >= nowr){
            nowl = a[i].l;
            nowr = a[i].r;
            ans++;
            continue;
        }
        if(a[i].r >= nowr)
            continue;
        else if(a[i].r < nowr){
            nowl = a[i].l;
            nowr = a[i].r;
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