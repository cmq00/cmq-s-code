#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
double x[N];
double fx[N];
double gx[N];
double ans[N];
double c[N],d[N];

void solve()
{
    int n,m;
    double a,b;
    scanf("%d %d %lf %lf",&n,&m,&a,&b);
    for(int i = 1;i <= n;++i){
        scanf("%lf",&x[i]);
        fx[i] = x[i] * a + b;
    }
    for(int i = 1;i <= m;++i){
        scanf("%lf %lf",&c[i],&d[i]);
    }
    double res;
    for(int i = 1;i <= n;++i){
        gx[i] = x[i] * c[1] + d[1];
    }
    for(int i = 1;i <= n;++i){
        ans[1] += abs(gx[i] * a + b - x[i]) + abs(fx[i] * c[1] + d[1] - x[i]);
    }
    for(int i = 2;i <= n;++i){
        gx[i] = (gx[i] - d[i - 1]) / c[i - 1];
       ans[i] += abs(gx[i] * a + b - x[i]) + abs(fx[i] * c[i] + d[i] - x[i]);
    }
    for(int i = 1;i <= m;++i){
        printf("%f\n",ans[i]);
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}