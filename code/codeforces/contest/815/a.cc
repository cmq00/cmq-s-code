#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

ll gcd(ll n,ll m)
{
    return m ? gcd(m,n % m):n;
}

void solve()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == 0 && c == 0){
        puts("0");
        return ;
    }
    if(a == 0 || c == 0){
        puts("1");
        return ;
    }
    ll A = a / gcd(a,c);
    ll C = c / gcd(a,c);
    ll B = b / gcd(b,d);
    ll D = d / gcd(b,d);
    ll AA = A * D;
    ll BB = C * B;
    ll AAA = AA / gcd(AA,BB);
    ll BBB = BB / gcd(AA,BB);
    // cout << A << " " << B << " " << C << " " << D << endl;
    // cout << AA << " " << BB << endl;
    if(AAA == 1 && BBB == 1){
        puts("0");
        return ;
    }
    if(AAA == 1 || BBB == 1){
        puts("1");
        return ;
    }
    puts("2");
    return;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}