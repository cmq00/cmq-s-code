#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

struct Point
{
    int x,y;
    double dis1;
    double dis2;
    double time;
}p[1004];

bool cmp(Point a,Point b)
{
   //return a.dis1 + a.dis2 < b.dis1 + b.dis2;
   return a.time < b.time;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> p[i].x >> p[i].y;
        p[i].dis1 = sqrt(p[i].x * p[i].x + p[i].y * p[i].y);
    }
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    double v1,v2;
    cin >> v1 >> v2;
    for(int i = 1;i <= n;++i){
        p[i].dis2 = sqrt((tx - p[i].x) * (tx - p[i].x) + (ty - p[i].y) * (ty - p[i].y));
        p[i].time = p[i].dis1 / v1 + p[i].dis2 / v2;
    };
    sort(p + 1,p + 1 + n,cmp);
    double res = sqrt((tx - sx) * (tx - sx) + (ty - sy) * (ty - sy)) / v1;
    // double res2 = p[1].dis1 / v1 + p[1].dis2 / v2;
    // double ans = min(res1,res2);
    printf("%.12lf\n",min(p[1].time,res));
    //cout << sqrt(5) + sqrt(5) / 1000 << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}