#include <bits/stdc++.h>
#define ll long long
using namespace std;
 int a[10005];
void solve()
{
    int n;
    cin >> n;
    if(n == 1 || n == 2){
        cout << n << endl;
        return ;
    }
    int sum = 0;
    if(n % 3 == 1){
        for(int i = 1;sum != n;++i){
            cout << a[i];
            sum += a[i];
        }
        cout << endl;
    }
    else{
        for(int i = 2;sum != n;++i){
            cout << a[i];
            sum += a[i];
        }
        
        cout << endl;
    }
}
 
int main(){
    //ios_base::sync_with_stdio(0);
    a[1] = 1;
    for(int i = 2;i <= 10004;++i){
        if(a[i - 1] == 1)
            a[i] = 2;
        else
            a[i] = 1;
    }
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}