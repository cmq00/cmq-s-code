#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int a[10004];
    int n;
    cin >> n;
    int flag = 0;
    a[0] = -1;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(a[i] < a[i - 1]){
            flag = 1;
        }
    }
    if(flag == 1)
        puts("Yes");
    else
        puts("No");
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}