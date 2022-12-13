#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[10] = {2,3,4,5,6,7,8,9};

int check(int n)
{
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
void solve()
{
    int n;
    cin >> n;
    int f = check(n);
    for(int i = 0;i <= 7;++i){
        if(check(n * a[i]) != f){
            puts("NO");
            return ;
        }
    }
    cout << f << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}