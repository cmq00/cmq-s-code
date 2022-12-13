#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4;

struct Point
{
    int x1,y1,x2,y2;
};

bool cmp(Point a,Point b)
{
    if(a.x1 == b.x1)
        return a.x2 < b.x2;
    return a.x1 < b.x1;
}

void solve()
{
    Point a[N];
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    sort(a + 1,a + 1 + n,cmp);
    //for(int i = 1;i <= n;++i)
        //printf("%d %d\n",a[i].x1,a[i].x2);
    ll ans = 0;
    for(int i = 1;i <= n;++i){
        if(a[i].x1 >= a[i - 1].x2){
            ans += a[i].x2 - a[i].x1;
            //cout << ans << endl;
        }
        else{
            if(a[i].x2 >= a[i - 1].x2)
                ans += a[i].x2 - a[i - 1].x2;
                //cout << ans << endl;
            else
                a[i].x2 = a[i - 1].x2;
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