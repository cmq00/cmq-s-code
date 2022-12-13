#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a,b,c;
    a = n / 3;
    b = n / 3 + 1;
    c = n / 3 - 1;
    if(n % 3 != 0){
        int d = n % 3;
        if(d == 1){
            b += 1;
        }
        else{
        int e = ceil(d / 2);
        b += e;
        a += d - e;
        }
    }
    cout << a << " " << b << " " << c << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}