#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int a[200];
const int N = 1e9;

void solve()
{
   int n;
   cin >> n;
   if(n > 19)
        puts("NO");
    else{
        cout << "YES" << endl;
        for(int i = 0;i < n;++i){
            cout << " " << a[i];
        }
        cout << endl;
    }
}
 
int main(){
    //ios_base::sync_with_stdio(0);
    for(int i = 0;i <= 20;++i){
        a[i] = pow(3,i);
        //cout << a[i] << " ";
    }
    //cout << endl;
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}