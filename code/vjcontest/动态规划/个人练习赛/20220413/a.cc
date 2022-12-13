#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[200];
int sume[200];
int sumo[200];

void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(a[i] % 2){
            sumo[i] = sumo[i - 1] + 1;
            sume[i] = sume[i - 1];
        }
        else{
            sumo[i] = sumo[i - 1];
            sume[i] = sume[i - 1] + 1;
        }
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