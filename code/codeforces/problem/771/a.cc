#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int n,a[600];
    cin >> n;
    int l = 0,r = 0,tr = 0;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= n;++i){
        if(a[i] == tr)
            {r = i;break;}
        if(a[i] != i && l == 0)
            l = i,tr = i;
        
    }
    //printf("l:%d r:%d\n",l,r);
    for(int i = l,j = r;i <= j;++i,--j){
        swap(a[i],a[j]);
    }
    for(int i = 1;i <= n;++i)
        cout << a[i] << " ";
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}