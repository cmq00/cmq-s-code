#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 4;
int a[N];
int ans[N];

void Swap(int l,int r)
{

}
void solve()
{
    int n;
    cin >> n;
    if(n % 2 == 0){
        puts("NO");
        return ;
    }
    puts("YES");
    for(int i = 1;i <= 2 * n;++i){
        a[i] = i;
    }
    ans[1] = 1;
    ans[2 * n] = 2 * n;
    ans[2 * n + 1] = 2 * n + 1;
    for(int i = 2;i <= n;++i)
        ans[i] = ans[i - 2] + 4;
    for(int i = 2 * n - 1;i >= n + 1;--i){
        ans[i] = ans[i + 2] - 4;
    }   
    for(int i = 1;i <= 2 * n;++i)
        cout << ans[i] << " ";
    cout << endl;
}
 
int main(){
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}