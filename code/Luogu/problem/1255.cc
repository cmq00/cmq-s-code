#include <bits/stdc++.h>
#define ll long long

using namespace std;

int nt[] = {1,2};
const int N = 5004;
int ans,x = 0;
queue<int> q;

int main()
{
    ll a[5010];
    a[1] = 1;a[2] = 2;
    for(int i = 3;i <= 5009;++i)
        a[i] = a[i - 1] + a[i - 2];
    int n;
    cin >> n;
    cout << a[n] << endl;
    return 0;
}