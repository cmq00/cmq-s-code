#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e5 + 4;
ll a[N];
ll b[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i){
        cin >> b[i];
    }
    int pos = 1;
    for(int i = 1;i <= n;++i){
        while(a[i] > b[pos])
          pos++;
        cout << b[pos] - a[i] << " "; 
          
    }
    puts("");
    pos = n;
    vector<int> v;
    for(int i = n;i >= 1;--i){
        int p = lower_bound(b + 1,b + 1 + n,a[i]) - b;
        //cout << p << endl;
        if(p == i){
            if(pos){
                v.push_back(b[pos] - a[i]);
                pos = 0;
            }
            else{
                v.push_back(b[p] - a[i]);
            }
        }
        else{
            if(pos == 0){
                pos = i;
            }
            v.push_back(b[pos] - a[i]);
        }
    }
    for(int i = v.size() - 1;i >= 0;--i){
        cout << v[i] << " ";
    }
    puts("");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}