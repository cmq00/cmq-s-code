#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))


 
using namespace std;

void solve()
{
    double pi = acos(-1);
    cout << pi << endl;
    double n = 2022;
    double b = n / 2.0;
   double a1 = b * b * 2;
   double a2 = (pi * b * b) / 2;
   cout << a1 + a2 << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}