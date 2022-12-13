#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{   
    int a[1004];
    int n,m,k;
    cin >> n >> m >> k;
    //cout << n << m << k;
    while(k--){
        stack<int> s1;
        stack<int> s2;
        s1.push(0);
        s2.push(0);
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        for(int i = 1;i <= n;++i){   
            if(a[i] == s2.top() + 1)
                s2.push(a[i]);
            else
                s1.push(a[i]);
            if(s1.size() > m + 1){
                puts("NO");
                return ;
            }
            while(s1.top() == s2.top() + 1){
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
    //printf("s2:%lu\n",s2.size());
        if(s2.size() == n + 1)
            puts("YES");
        else
            puts("NO");
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    solve();
    return 0;
}