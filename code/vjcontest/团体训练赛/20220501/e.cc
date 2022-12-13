#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int cnt;

void solve()
{
    double r,h;
    cin >> r >> h;
    double x0,y0,z0,x1,y1,z1;
    double vx,vy,vz,V;
    cin >> x0 >> y0 >> z0;
    cin >> vx >> vy >> vz;
    V = sqrt(vx * vx + vy * vy + vz * vz);  
    double t0;
    t0 = (-z0) / vz;
    x1 = vx * t0 + x0,y1 = vy * t0 + y0,z1 = 0;
    double a,b,c;
    a = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
    b = 2 * x0 * (x1 - x0) + 2 * y0 * (y1 - y0);
    c = x0 * x0 + y0 * y0 - r * r;
    double t11,t12;
    t11 = (-b - sqrt(b * b - 4 * a *c) / 2 * a);
    t12 = (-b + sqrt(b * b - 4 * a *c) / 2 * a);
    double x2,y2,z2 = 0;
    x2 = (x1 - x0) * t11 + x0;
    y2 = (y1 - y0) * t11 + y0;
    double t3;
    t3 = (x2 * y2 - x0 * vy * vx + vx * y0 - y2 * vx) / (y2 * vx - x2 * vy);
    double x3,y3,z3 = 0;
    x3 = x2 * t3 + x2;
    y3 = y2 * t3 + y2;
    double d1 = sqrt((x3 - x0) * (x3 - x0) + (y3 - y0) * (y3 - y0) + (z3 - z0) * (z3 - z0));
    double x22,y22,z22 = 0;
    x22 = (x1 - x0) * t12 + x0;
    y22 = (y1 - y0) * t12 + y0;
    double t4;
    t4 = (x22 * y22 - x0 * vy * vx + vx * y0 - y22 * vx) / (y22 * vx - x22 * vy);
    double x4,y4,z4 = 0;
    x4 = x2 * t4 + x2;
    y4 = y2 * t4 + y2;
    double d2 = sqrt((x4 - x0) * (x4 - x0) + (y4 - y0) * (y4 - y0) + (z4 - z0) * (z4 - z0));
    double d = min(d1,d2);
    double ans = d / V;
    printf("%.10lf\n",ans);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}