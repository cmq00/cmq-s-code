#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> v1;
    vector<int> v2;
    int cnt1 = 0;
    int cnt2 = 0;
    int nn = n;
    while(n){
        int xx = n % x;
        n /= x;
        if(xx == 1)
            cnt1++;
    }
    while(nn){
        int yy = nn % y;
        nn /= y;
        if(yy == 1)
            cnt2++;
    }
    //cout << cnt1 << cnt2;
    if(cnt1 > cnt2)
        puts(">");
    else if(cnt1 < cnt2)    
        puts("<");
    else
        puts("=");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}