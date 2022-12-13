#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n;
    cin >> n;
    char a[3][10004];
    for(int i = 0;i <= 1;++i){
        for(int j = 1;j <= n;++j){
            cin >> a[i][j];
        }
    }
    for(int j = 1;j <= n;++j){
        if(a[1][j] == 'R'){
            if(a[0][j] != 'R'){
                puts("NO");
                return ;
            }
        }
        if(a[0][j] == 'R'){
            if(a[1][j] != 'R'){
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