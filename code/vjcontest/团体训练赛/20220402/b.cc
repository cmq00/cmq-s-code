#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4;
int id[N];
int hp[N];
bool vis[N];
bool vis2[N];
int cnt[N];

void solve()
{
    memset(hp,0,sizeof(hp));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= n;++i){
        cin >> id[i];
        vis2[i] = 1;
        cnt[id[i]]++;
    }
    for(int i = 1;i <= n;++i){
        if(vis2[id[i]])
            vis[i] = 0,vis2[id[i]] = 0;
        else
            vis[i] = 1,vis2[id[i]] = 1;
    }
    /*for(int i = 1;i <= n;++i)
        cout << vis[i] << " ";
    cout << endl;*/
    int l = k / n;
    int y = k % n;
    for(int i = 1;i <= n;++i){
        if(cnt[id[i]] % 2){
            if(vis[i] == 0)
                hp[i] = (l / 2);
            else
                hp[i] = ((l + 1) / 2);
        }
        else{
            if(vis[i] == 0)
                hp[i] = 0;
            else
                hp[i] = l;
        }
    }
    /*for(int i = 1;i <= n;++i){
        if(i == 1)
            cout << hp[i];
        else
            cout << " " << hp[i];
    }*/
    //cout << endl;
    if(l % 2 == 0){
        for(int i = 1;i <= y;++i){
            hp[i] += vis[i];
        }
    }
    else{
        for(int i = 1;i <= y;++i){
            if(cnt[id[i]] % 2)
                hp[i] += (1 - vis[i]);
            else
                hp[i] += vis[i];
        }
    }
    for(int i = 1;i <= n;++i){
        if(i == 1)
            cout << hp[i];
        else
            cout << " " << hp[i];
    }
    cout << endl;
    //return 0;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}