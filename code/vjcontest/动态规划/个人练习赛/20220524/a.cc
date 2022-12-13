#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[104];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    bool f = 1;
    int ans = 0;
    for(int i = 2;i <= n;++i){
        if((a[i] == 2 && a[i - 1] == 3) || (a[i] == 3 && a[i - 1] == 2)){
            f = 0;
            break;
        }
        if(a[i] == 2 && a[i - 1] == 1){
            ans += 3;
        }
        if(a[i] == 3 && a[i - 1] == 1){
            ans += 4;
        }
        if(a[i] == 1){
            if(a[i - 1] == 2)
                ans += 3;
            else
                ans += 4;
        }
    }
    if(f){
        puts("Finite");
        cout << ans << endl;
    }
    else{
        puts("Infinite");
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}