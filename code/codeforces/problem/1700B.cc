#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int num;
    cin >> num;
    vector<int> v;
    while(num){
        v.push_back(num % 10);
        num /= 10;
    }
    reverse(v.begin(),v.end());
    int len = v.size();
    if(v[0] == v[len - 1] && v[0] == 9);
    for(int i = 0;i < v.size();++i)
        cout << v[i];
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}