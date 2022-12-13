#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int a,b,k;
    cin >> a >> b >> k;
    vector<int> v;
    if(a < b)
        v.push_back(0);
    else{
        v.push_back(a / b);
        int x = a / b;
        a -= b * x;
    }
    k += 1;
    while(k--){
        if(a < b)
            a *= 10;
        //else    
            //a -= a - b * (a / b);
        int x = a / b;
        v.push_back(x);
        a = a - b * x;
    }
    int len = v.size();
    if(v[len - 1] >= 5)
        v[len - 2]++;
    cout << v[0] << ".";
    for(int i = 1;i <= len - 2;++i)
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