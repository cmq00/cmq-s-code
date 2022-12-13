#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    int a[100];
    for(int i = 0;i < n;++i)
        a[i + 1] = n - i;
    for(int i = 1;i <= n;++i)   
        cout << a[i] << " ";
    cout << endl;
   int m = n - 1;
   int j = n;
   while(m--){
       swap(a[j],a[j - 1]);
       for(int i = 1;i <= n;++i)
           cout << a[i] << " ";
        cout << endl;
        j--;
   }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}