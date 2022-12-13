#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e9 + 4;
double a[N];

void solve()
{
    double n;
    cin >> n;
    double aver = 0;
    double sum = 0;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        sum += a[i];
    }
    aver = sum / n;
    int ans = 0;
    for(int i = 1;i <= n;++i){
        if(a[i] > aver)
            ans++;
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