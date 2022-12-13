#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cnt[200];
const int N = 1e5 + 4;
//int a[N];

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    char w[200][2000];
    for(int i = 1;i <= n;++i){
        for(int j = 0;j < m;++j){
            cin >> w[i][j];
        }
    }
    int x;
    stack<char> s;
    vector<char> v;
    while(cin >> x && x != -1){
        if(x != 0){
            if(s.size() == k){
                char ch = s.top();
                s.pop();
                v.push_back(ch);
            }
            if(cnt[x] <= n){
                s.push(w[x][cnt[x]]);
                cnt[x]++;
            }
        }
        else{
            if(!s.empty()){
                char ch = s.top();
                s.pop();
                v.push_back(ch);
            }
        }
    }
    for(int i = 0;i < v.size();++i)
        cout << v[i];
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}