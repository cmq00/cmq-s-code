#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t,flag;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        flag = 1;
        if(n == 1 || n == 0)
            cout << "NO" << endl;
        else{
            for(ll i = 2;i * i <= n;++i){
                if(n % i == 0){
                    flag = 0;
                    break;
                }
            }
        
            if(flag == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}