#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

char mp[100][100];

void solve()
{
    for(int i = 1;i <= 8;++i){
        for(int j = 1;j <= 8;++j){
            cin >> mp[i][j];
        }
    }
    for(int i = 1;i <= 8;++i){
        int cnt = 1;
        int x,y;
        for(int j = 1;j <= 8;++j){
            if(mp[i][j] == '#'){
                cnt++;
                x = i,y = j;
            }
        }
        if(cnt == 1){
            cout << x << y << endl;
            return ;
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