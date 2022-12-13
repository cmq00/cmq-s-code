#include <cstdio>
#include <iostream>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
   
    int sm = abs(1 - n) + abs(m - 1);
    int ss = n - 1 + m - 1;
    int ans = 0;
    if(n == 1 && m == 1)
    {
        cout << 0 << endl;
        return ;
    }
    if(m == 1 || n == 1){
        cout << sm + 1 << endl;
        return ;
    }
    if(n > m){
        cout << sm + m << endl;
    }
    else{
        cout << ss + n << endl;
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