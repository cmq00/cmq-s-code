#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

struct Node
{
    string a,b;
};

void solve()
{
    int n;
    cin >> n;
    map<string,int> mp;
    Node p[10004];
    int tot = 0;
    for(int i = 1;i <= n;++i){
        cin >> p[i].a >> p[i].b;
        if(!mp[p[i].a])
            mp[p[i].a] = ++tot;
    }
    vector<string> v[14];
    for(int i = 1;i <= n;++i){
        int j = mp[p[i].a];
        v[j].push_back(p[i].b);
    }
    bool f = 0;
    for(int i = 1;i <= tot;++i){
        for(int j = 0;j < v[i].size();++j){
            cout << v[i][j] << " ";
        }
    }
    cout << endl;
    for(int i = 1;i <= tot;++i){
        int cnt = 1;
        for(int j = 1;j < v[i].size();++j){
            if(v[i][j] == v[i][j - 1])
                cnt = 0;
            else    
                cnt++;
        }
        if(cnt >= 5)
            f = 1;
    }   
    if(f)
        puts("PENTA KILL!");
    else
        puts("SAD:(");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}