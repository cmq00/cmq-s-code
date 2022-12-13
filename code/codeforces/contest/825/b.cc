#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
int a[N],b[N];

int gcd(int n,int m)
{
    return m ? gcd(m,n % m):n;
}

void solve()
{
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    if(n == 1 || n == 2){
        puts("YES");
        return ;
    }
    for(int i = 1;i <= n;++i){
        if(a[i] != 1){
            if(mp[a[i]] >= 2){
                puts("NO");
                return ;
            }
        }
    }
    puts("YES");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}