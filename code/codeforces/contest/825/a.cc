#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[400],b[400];

void solve()
{
    int n;
    cin >> n;
    int cnta = 0,cntb = 0;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(a[i] == 1)
            cnta++;
    }
    for(int i = 1;i <= n;++i){
        cin >> b[i];
        if(b[i] == 1)
            cntb++;
    }
    
    int cnt = 0;
    for(int i = 1;i <= n;++i){
        if(a[i] != b[i])
            cnt++;
    }
    if(cnt == 0){
        cout << "0" << endl;
        return ;
    }
    if(cnta == cntb){
        cout << "1" << endl;
        return ;
    }   
    if(cnt > min(max(cnta,cntb) - min(cnta,cntb),max(n - cnta,n - cntb) - min(n - cnta,n - cntb)))
        cout << min(max(cnta,cntb) - min(cnta,cntb),max(n - cnta,n - cntb) - min(n - cnta,n - cntb)) + 1 << endl;
    else
        cout << min(max(cnta,cntb) - min(cnta,cntb),max(n - cnta,n - cntb) - min(n - cnta,n - cntb)) << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}