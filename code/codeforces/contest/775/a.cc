#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int a[1000];
    int n,flag = 1;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(a[i] != 1)
            flag = 0;
    }
    int ans = 0;
    int pos,end;
    for(int i = 1;i <= n;++i){
        if(a[i] != 1){
            pos = i - 1;
            break;
        }
    }
    for(int i = n;i >= 1;--i){
        if(a[i] != 1){
            end = i + 1;
            break;
        }
    }
    if(flag == 1)
        cout << "0" << endl;
    else
    cout << end - pos << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}