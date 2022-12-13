#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
ll p[N],c[N];

void solve()
{   
    int n,m = 0,k;
    cin >> n;
    for(ll i = 2;i <= sqrt(n);++i){
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
    for(int i = 1;i <= m;++i){
        if(c[i] > 1){
            if(i == 1)
                cout << p[i] << "^" << c[i];
            else
                cout << "*" <<  p[i] << "^" << c[i];
        }
        else{
            if(i == 1)
                cout << p[i];
            else
                cout << "*" << p[i];
        }
    }
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}