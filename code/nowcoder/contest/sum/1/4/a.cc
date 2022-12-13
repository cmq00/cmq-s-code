#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;

struct Node
{
    ll w;
    double p;
}a[N];

bool cmp(Node a,Node b)
{
    return a.w > b.w;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        cin >> a[i].w;
    }
    for(int i = 1;i <= n;++i){
        double x;
        cin >> x;
        a[i].p = x / 10000;
    }
    sort(a + 1,a + 1 + n,cmp);
    for(int i = 1;i <= n;++i){
        cout << a[i].w << " " << a[i].p << endl;
    }
    a[0].p = 1;
    double ans = 0;
    double res = 1;
    for(int i = 1;i <= m;++i){
        res = 1;
        for(int j = 1;j <= i - 1;++j){
            res *= a[j].p;
        }
        ans += a[i].w * res;
    }   
    printf("%.16lf\n",ans);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}