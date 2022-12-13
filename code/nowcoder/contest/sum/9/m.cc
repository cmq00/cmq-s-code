#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

double a[4][5] = {1,1,0.8,0.5,0,2,2,1.6,1.0,0,3,3,2.4,1.5,0,5,5,2.5,2,0};
double t[] = {1,0.5,0.4,0.3,0};

void solve()
{
    
    double A = 0,B = 0;
    double A0 = 0,B0 = 0;
    double ans = 0;
    for(int i = 0;i < 4;++i){
        for(int j = 0;j < 5;++j){
            double x;
            cin >> x;
            A += x * a[i][0];
            A0 += a[i][j] * x;
            if(i == 3){
                    B0 += t[j] * x;
                    B += x * t[0];
            }
        }
    }
    ans = A0 / A + B0 / B * 0.01;
    printf("%.9lf\n",ans * 100);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}