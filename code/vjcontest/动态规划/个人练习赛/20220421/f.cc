#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

char arr[] = {0,1,2,3,4,5,6,7,8,9,'A','B','C','D','E','F'};
map<char,int> mp;

void solve()
{
    int a,b;
    string n;
    cin >> a >> n >> b;
    int len = n.size();
    ll res = 0;
    for(int i = 0;i <= len;++i){
        if('0' <= n[i] && n[i] <= '9')
            res += (n[i] - '0') * pow(a,len - i - 1);
        else
            res += mp[n[i]] * pow(a,len - i - 1);
    }
    //cout << res << endl;
    stack<int> s;
    while(res){
        int x = res % b;
        s.push(x);
        res /= b;
    }
    while(!s.empty()){
        int x = s.top();
        if(0 <= x && x <= 9)
            cout << x;
        else
            cout << arr[x];
        //cout << "x: " << x << " " <<  arr[x] << endl;
        s.pop();
    }
    cout << endl;
}

int main()
{
    mp['a'] = mp['A'] = 10,mp['b'] = mp['B'] = 11;
    mp['c'] = mp['C'] = 12;mp['d'] = mp['D'] = 13;
    mp['e'] = mp['E'] = 14;mp['f'] = mp['F'] = 15;
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}