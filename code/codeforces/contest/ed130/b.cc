#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e5 + 4;
int a[N];
ll sum[N];

bool cmp(int aa,int b)
{
    return aa > b;
}

void solve()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;++i){
        sum[i] = sum[i - 1] + a[i];
    }
    
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << sum[n - x + y] - sum[n - x] << endl;
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