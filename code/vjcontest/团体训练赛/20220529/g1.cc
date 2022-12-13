#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int fun(int n){
    int ans = 1;
    while(n){
        int x = n % 10;
        ans *= x;
        n /= 10;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    int ans = 1;
    while(n){
        n = fun(n);
        //cout << n << endl;
        if(n < 10)
            break;
    }
    cout << n << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}