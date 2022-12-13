#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e3 + 4;
int a[N];
vector<int> b;

void solve()
{
    int n;
    ll sum1 = 0,sum2 = 0;
    ll A = 0,B = 0;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(a[i] >= 0)
            sum1 += a[i];
        else
            sum2 += a[i];
    }
    sort(a + 1,a + 1 + n);
    //cout << sum1 << " "<< sum2 << endl;
    /*for(int i = 1;i <= n;++i)
        cout << a[i] << " ";
    cout << endl;*/
    int cnt = 1;
    if(abs(sum1) >= abs(sum2)){
        for(int i = n;i >= 1;--i){
            if(cnt % 2)
                A += a[i];
            else
                B += a[i];
            cnt++;
        }
    }
    else{
        for(int i = 1;i <= n;++i){
            //cout << "cnt: " << cnt << endl;
            if(cnt % 2)
                A += a[i];
            else
                B += a[i];
            cnt++;
        }
    }
    //cout << A << " " << B << endl;
    cout << abs(A) - abs(B) << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}