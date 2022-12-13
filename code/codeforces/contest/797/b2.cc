#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 5e4 + 4;
int a[N];
int b[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i){
        cin >> b[i];
        if(a[i] < b[i]){
            puts("NO");
            return ;
        }
    }
    vector<int> v1;
    vector<int> v2;
    for(int i = 1;i <= n;++i){
        if(b[i] == 0)
            v2.push_back(a[i]);
        else
            v1.push_back(a[i] - b[i]);
    }
    bool f = 1;
    if(v1.size() >= 2){
    for(int i = 1;i < v1.size();++i){
        if(v1[i] != v1[i - 1]){
            puts("NO");
            return ;
        }
    }
    }
    if(v1.empty())
        v1.push_back(1000000004);
    for(int i = 0;i < v2.size();++i){
        if(v2[i] > v1[0]){
            puts("NO");
            return ;
        }
    }
    puts("YES");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}