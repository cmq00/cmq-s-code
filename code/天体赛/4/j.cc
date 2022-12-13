#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    int a[2000];
    while(k--){
        stack<int> s1;
        stack<int> s2;
        while(!s1.empty())
            s1.pop();
        while(!s2.empty())
            s2.pop();
        int f = 1;
        for(int i = 1;i <= m;++i){
            cin >> a[i];
        }
        for(int i = m;i >= 1;--i)
            s2.push(a[i]);
        /*while(!s2.empty()){
            int x = s2.top();
            cout << x;
            s2.pop();
        }*/
        for(int i = 1;i <= m;++i){
            s1.push(i);
            if(!s1.empty() && s1.size() > n){
                //cout << " k: " << s1.size() << endl;
                f = 0;
                break;
            }
            while(!s1.empty() && !s2.empty() && s1.top() == s2.top())
                s2.pop(),s1.pop();
            
        }
        //cout << "f: " << f << endl;
        //cout << s2.size() << endl;
        if(f == 0 || !s2.empty())
            puts("NO");
        if(s2.empty())
            puts("YES");
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}