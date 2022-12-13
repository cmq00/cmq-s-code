#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int a[1000];
    int n;
    long long sum = 0;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n - 1;++i){
        a[i + 1] = a[i] | a[i + 1];

    }
    cout << a[n] << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}