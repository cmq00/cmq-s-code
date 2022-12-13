#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int N = 5e3 + 4;
int a[N];

bool cheak(int l,int r)
{
    for(int i=  l,j = r;i <= j;++i,--j){
        if(a[i] != a[j]){
            return 0;
        }
    }
    return 1;
}

void solve()
{
    int n;
    int flag = 0;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n - 2;++i){
        if(flag == 1)
            break;
        for(int j = i + 2;j <= n;++j){
            if(cheak(i,j))
                {flag = 1;continue;}
            //else
                //continue;
        }
    }
    if(flag == 1)
        puts("YES");
    else
        puts("NO");
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}
