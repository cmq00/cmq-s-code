#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 2e5 + 4;
ll a[N];

int solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    int flag = 1;
    ll sum1 = a[1] + a[2],sum2 = a[n];
    if(sum1 < sum2)
        return 1;
    for(int i = 3,j = n - 1;;++i,--j){
        if(i >= j)
            break;
        sum1 += a[i],sum2 += a[j];
        if(sum1 < sum2)
            return 1;
    }
    return 0;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--){
        if(solve() == 1)
            puts("YES");
        else    
            puts("NO");
    }
    return 0;
}