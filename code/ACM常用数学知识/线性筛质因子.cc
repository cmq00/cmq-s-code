#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int main()
{
    int v[N],prime[N];
    int n = N - 1;
    fill(v,v + N,0);
    int m = 0;
    //求每个数最小质因数 && 筛素数
    for(int i = 2;i <= n;++i){
        if(v[i] == 0){
            v[i] = i;//如果v[i] == 0，则i是素数，令v[i] = i；
            prime[++m] = i;
        }
        for(int j = 1;j <= m;++j){
            if(prime[j] > v[i] || prime[j] > n / i) //prime[j] > n / i 防止越界
                break;
            v[i * prime[j]] = prime[j];
        }
    }
    //每个数不同质因数个数
    int d[N];//记录每个数的质因数个数；
    fill(v,v + n,0);
    m = 0;
     for(int i = 2;i <= n;++i){
        if(v[i] == 0){
            v[i] = i;//如果v[i] == 0，则i是素数，令v[i] = i；
            prime[++m] = i;
            d[i] = 1;//素数质因子只有一个；
        }
        for(int j = 1;j <= m;++j){
            if(prime[j] > v[i] || prime[j] > n / i) //prime[j] > n / i 防止越界
                break;
            v[i * prime[j]] = prime[j];
            if(v[i] == prime[j])
                d[i * prime[j]] = d[i];
            else    
                d[i * prime[j]] = d[i] + 1;
        }
    }
    /*int cnt = 0;
     for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            p[cnt++] = i;
            f[i] = 1;
        }
        for (int j = 0; j < cnt && i * p[j] <= N; j++)
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                f[i * p[j]] = f[i];
                break;
            }
            f[i * p[j]] = f[i] + 1;
        }
    }*/
    int x;
    while(cin >> x)
        cout << d[x] << endl;;
    return 0;
}
