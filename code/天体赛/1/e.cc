#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool vis[10004];

void solve()
{
    string a;
    getline(cin,a);
    int len = a.size();
    int cnt = 0;
    for(int i = 0;i < len;++i){
        if(a[i] != '6' || vis[i]){
            cout << a[i];
            cnt = 0;
        }
        if(a[i] == '6' && !vis[i]){
            for(int j = i;a[j] == '6';++j){
                cnt++;
                vis[j] = 1;
            }
            if(cnt > 9){
                cout << "27";
                i += cnt - 1;
            }
            if(cnt > 3 && cnt <= 9){
                cout << "9";
                i += cnt - 1;
            }
            if(cnt <= 3){
                cout << "6";
            }
        }
    }
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