#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

char mp[504][504];

void solve()
{
    int n,k,r,c;
    cin >> n >> k >> r >> c;
    int t = n / k;
    if(k == 1){
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j){
                cout << "X";
            }
            puts("");
        }
        return ;
    }
    for(int i = 1;i <= k;++i){
        if(r > k)
            r %= k;
        if(r == 0)
            r = k;
        if(c > k)
            c %= k;
        if(c == 0)
            c = k;
        mp[r][c] = 'X';
        r++,c++;
    }
    for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
            if(mp[i][j] != 'X')
                mp[i][j] = '.';
        }
    }
    for(int i = 1;i <= n;++i){
        int ii = i > k ? i % k : i;
        if(ii == 0)
            ii = k;
        for(int j = 1;j <= t;++j){
            for(int l = 1;l <= k;++l){
                cout << mp[ii][l];
            }
        }
        puts("");
    }
     for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
                mp[i][j] = '.';
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