#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;

struct Node
{
    int pos;
    int v;
}a[N];
int b[N];

bool cmp(Node a,Node b)
{
    return a.v < b.v;
}

void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;++i){
        cin >> a[i].v;
        a[i].pos = i;
    }
    for(int i = 1;i <= n;++i){
        cin >> b[i];
    }
    sort(a + 1,a + 1 + n,cmp);
    sort(b + 1,b + 1 + n);
    ll cnt = 0;
    vector<int> ans;
    for(int i = 1;i <= n;++i){
        ans.
        if(a[i].v < b[i]){
            cnt += b[i] - a[i].v;
            ans.push
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}