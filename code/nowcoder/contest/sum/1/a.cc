#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const ll N = 2e5 + 7;
const double pi = 3.1415926535, ssr = 1e-7;
double c, x, y, d;

double arcos(double x)
{
    double l = 0, r = pi / 2;
    while(r - l >= ssr)
    {
        double m = (l + r) / 2;
        if(cos(m) > x)
            l = m;
        else
            r = m;
    }
    return l;
}

void yyds(double x1, double y1, double x2, double y2)
{
    double a1 = sqrt(x1 * x1 + y1 * y1), a2 = sqrt(x2 * x2 + y2 * y2);
    double a3 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double ccc = (a1 * a1 + a2 * a2 - a3 * a3) / (2 * a1 * a2);
    if(ccc >= 0)
        printf("%.7f", arcos(ccc) * c);
    else
        printf("%.7f", (pi - arcos(-ccc)) * c);
}

bool check(double x, double y)
{
    if(x * x + y * y >= c * c)
        return 1;
    return 0;
}

bool six(double m)
{
    double y1 = m, x1 = sqrt(d * d - y1 * y1) + x;
    return check(x1, y1);
}

bool bbb(double m, double x1, double y1, double x2, double y2)
{
    double y3 = m, x3 = (x2 * x2 - x1 * x2 - y1 * y2 + y1 * m + y2 * y2 - y2 * m) / (x2 - x1);
    return check(x3, y3);
}

void planB()
{
    double l = 0, r = d;
    while(r - l >= ssr)
    {
        double m = (l + r) / 2;
        if(six(m))
            l = m;
        else
            r = m;
    }
    double y1 = l, x1 = sqrt(d * d - y1 * y1) + x;
    double x2 = 2 * x - x1, y2 = -y1;
    l = -c, r = y2;
    while(r - l >= ssr)
    {
        double m = (l + r) / 2;
        if(bbb(m, x1, y1, x2, y2))
            l = m;
        else
            r = m;
    }
    double y3 = l, x3 = (x2 * x2 - x1 * x2 - y1 * y2 + y1 * l + y2 * y2 - y2 * l) / (x2 - x1);
    yyds(x1, y1, x3, y3);
}


void planA(double x1, double x2)
{
    double l = 0, r = c;
    while(r - l >= ssr)
    {
        double m = (l + r) / 2;
        if(check(x1, m))
            r = m;
        else
            l = m;
    }
    double y1 = l;

    l = 0, r = c;
    while(r - l >= ssr)
    {
        double m = (l + r) / 2;
        if(check(x2, m))
            r = m;
        else
            l = m;
    }
    double y2 = l;
    yyds(x1, y1, x2, y2);
}

void solve()
{
    cin >> c >> x >> y >> d;
    if(!y)
    {
        x = sqrt(x * x + y * y);
        if(x < 0)
            x = -x;
        double x1 = x - d, x2 = x + d;
        if(x + d > c)
        {
            planB();
            return;
        }
        planA(x1, x2);
        return;
    }
    if(x < 0)
        x = -x;
    double x1 = x - d, x2 = x + d;
    if(x2 > c)
        planB();
    else
        planA(x1, x2);
}

int main()
{
    speed
    t()
    solve();
    return 0;
}arco