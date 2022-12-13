#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int gcd(int n,int m)
{
    return m ? gcd(m,n % m):n;
}

int a[4];

void solve()
{
    int n,k;
    cin >> n >> k;
    if(n % 2){
        printf("%d %d %d\n",(n - 1) / 2,(n - 1) / 2,1);
    }
    else{
        if(((n / 2) % 2) == 0){
            printf("%d %d %d\n",n / 2,(n - n / 2) / 2,(n - n / 2) / 2);
        }
        else{
            n -= 1;
            printf("%d %d %d\n",(n - 1) / 2,(n - 1) / 2,2);
        }
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