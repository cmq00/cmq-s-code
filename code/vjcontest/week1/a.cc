#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[200],b[200];

void solve()
{
    int n;
    int suma = 0,sumb = 0;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        suma += a[i];
    }
    for(int i = 1;i <= n;++i){
        cin >> b[i];
        sumb += b[i];
    }
    if(suma > sumb || sumb - suma > n){
        puts("NO");
        return ;
    }
    int k = sumb - suma;
    sort(a + 1,a + 1 + n);
    sort(b + 1,b + 1 + n);
    int cnt = 0;
    for(int i = 1;i <= n;++i){
        if(a[i] != b[i]){
            if(b[i] - a[i] >= 2){
                puts("NO");
                return ;
            }
                cnt++;
        }
    }
    if(cnt > k){
        puts("NO");
        return ;
    }
    puts("YES");
}

int main()//https://codeforces.com/problemset/problem/1584/C
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}