#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        ll n,x,y;
        cin >> n >> x >> y;
        for(int i = 1;i <= n;++i){
            int num;
            cin >> num;
            x += num;
        }
        //cout << x << endl;
        if((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0))
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;

}