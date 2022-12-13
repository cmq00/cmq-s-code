#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int a[100004],odd[100004],even[100004];
    int n;
    cin >> n;
    int j,k,flag = 1;
    j = k = 1;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(a[i] % 2 == 0)   
            even[j++] = a[i];
        else
            odd[k++] = a[i];
    } 
    for(int i = 1;i < j - 1;++i)
        if(even[i] > even[i + 1])
            {flag = 0;break;}
    
    for(int i = 1;i < k - 1;++i)
        if(odd[i] > odd[i + 1])
            {flag = 0;break;}
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