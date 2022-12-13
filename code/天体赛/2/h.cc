#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[10004];

void solve()
{
    vector<int> v;
    int k1,k2,n;
    cin >> k1 >> k2 >> n;
    v.push_back(k1),v.push_back(k2);
    for(int i = 2;i <= n;++i){
        int x = v[i - 1] * v[i - 2];
        if(x < 10)
            v.push_back(x);
        else{
            v.push_back(x / 10 % 10);
            v.push_back(x % 10);
        }
    }
    //cout << v.size() << endl;
    for(int i = 0;i < n;++i){
        if(i == 0)
            cout << v[i];
        else
            cout << " " << v[i];
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