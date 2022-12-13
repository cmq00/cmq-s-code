#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 4;
ll p[N],c[N];

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n,m = 0,k;
        cin >> n;
        for(ll i = 2;i <= sqrt(n);++i){
            cout << "n: " << n << endl;
            if(n % i == 0){
                p[++m] = i;
                c[m] = 0;
                while(n % i == 0){
                        n /= i;
                        c[m]++;
                }
            }
        }
        if(n > 1){
            p[++m] = n;
            c[m] = 1;
        }
        for(int i = 1;i <= m;++i)
            cout << p[i] <<" "<< c[i] << endl;
    }
    return 0;
}
