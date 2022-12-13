#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

bool vis[1000][1000];

void solve()
{
    ms(vis);
    int h,m;
    scanf("%d:%d",&h,&m);
    int x;
    cin >> x;
    int hx = x / 60;
    int mx = x - hx * 60;
    //cout << "hx: " << hx << " " << mx << endl;
    int cnt = 0;
    bool f = 1;
    int j = m;
    int i = h;
        while(1){
            if(j >= 60){
                j = j % 60;
                i++;
            }
           if(i >= 24){
                i = i % 24;
           }
            //cout  << i << endl;
            //cout << "j: " << j << endl;
            if(vis[i][j]){
                break;
            }
            vis[i][j] = 1;
            int a = i % 10,b = i / 10,c = j % 10,d = j / 10;
            if(a == d && b == c)
                cnt++;
            j += mx;
            //  if(mx == 0){
            //   i += 1;
            // }
             i += hx;
        } 
       
    cout << cnt << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}