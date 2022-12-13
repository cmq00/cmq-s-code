#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

char a[600][600];
int n,m;

void solve()
{
    cin >> n >> m;
    int cnt1 = 0,cnt0 = 0;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> a[i][j];
            if(a[i][j] == '1')
                cnt1++;
            else
                cnt0++;
        }
    }
    if(cnt1 == 0){
        puts("0");
        return ;
    }
    if(cnt0 == 0){
        cout << cnt1 - 2 << endl;
        return ;
    }
    //cout << cnt1 << " " << cnt0 << endl;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            if(a[i][j] == '0'){
                //cout << i << " " << j << endl;
                for(int k = 0;k < 4;++k){
                    int ti = i + dx[k];
                    int tj = j + dy[k];
                    //cout << ti << " " << tj << endl;
                    if(1 <= ti && ti <= n && 1 <= tj && tj <= m){
                        if(a[ti][tj] == '0'){
                            cout << cnt1 << endl;
                            return ;
                        }

                    }
                }
            }
        }
    }
    cout << cnt1 - 1 << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}