#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<ll> v;
    int cnt = 0;
    int nn = n;
    while(n){
        int x = n & 1;
        v.push_back(x);
        if(x == 1)
            cnt++;
        n >>= 1;
    }
    int len = v.size();
    if(k < cnt || k > nn){
        //printf("k:%d cnt:%d n%d
        puts("NO");
        return 0;
    }
    puts("YES");
    int num = k - cnt;
    //cout << "num: " << num << endl;    
    for(int i = len - 1;i >= 1;--i){
        while(num && v[i] != 0){
            v[i] -= 1;
            v[i - 1] += 2;
            num--;
        }
    }
    /*for(int i = 0; i < len;++i){
        cout << v[i] << " ";
    }*\
    cout << endl;*/
    ll ans = 0;
    for(int i = 0;i < len;++i){
        if(v[i])
            ans = pow(2,i);
        for(int j = 1;j <= v[i];++j){
            cout << ans << " ";
        }
    }
    cout << endl;
    return 0;
}
   
