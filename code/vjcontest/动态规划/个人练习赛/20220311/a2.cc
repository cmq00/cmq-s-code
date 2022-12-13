#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e3 + 4;
int pos[N],vis[N];
int a[N];

void solve()
{
    int n;
    cin >> n;
    memset(pos,0,sizeof(pos));
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i){
        if(!vis[a[i]]){
            vis[a[i]] = 1;
            pos[a[i]] = i;
        }
    }
    /*for(int i = 1;i <= n;++i)
        cout << "i:" << pos[i] << " ";
    cout << endl;*/
    int flag = 0;
    for(int i = n;i >= 1;--i){
        if(i != pos[a[i]] && i != pos[a[i]] + 1 && pos[a[i]])
            {flag = 1;break;}
    }
    if(flag == 1)
        puts("YES");
    else
        puts("NO");
}

int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}