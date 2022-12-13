#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;

const int N = 1e3 + 4;
int mp[N][N];
int n,m,sx,sy,d;
int vis[N][N],step[N][N];
int nx[] = {0,1,0,-1};
int ny[] = {1,0,-1,0};

void solve()
{
    cin >> n >> m >> sx >> sy >> d;
    int b = sy - d;
    int bb = sx + d;
    if(b > 1 && bb < n){
        cout << n + m - 2 << endl;
        return ;
    }    
    int c = sy + d;
    int cc = sx - d;
    if(c < m && cc > 1){
        cout << n + m - 2 << endl;
        return ;
    }
    cout << "-1" << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}