#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
 int sumW[1004],sumw[1004],W[1004],w[1004],ans[1004];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;++i){
        cin>>W[i];
        w[i] = W[i] / 2;
        sumW[i] = sumW[i - 1]+W[i];
        sumw[i]=sumw[i-1]+w[i];
    }
    for(int i = 1;i <= n;++i){
        for(int j = i;j <= n;++j){
            ans[sumW[j]-sumW[i-1]] = (ans[sumW[j]-sumW[i-1]] % mod + 1) % mod;
            ans[sumw[j]-sumw[i-1]] = (ans[sumw[j]-sumw[i-1]] % mod + 1) % mod;
        }
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            if(j == i)
                continue;
            for(int k = j;k <= n;++k)
                 ans[W[i] + sumw[k]-sumw[j-1]] = (ans[W[i] + sumw[k]-sumw[j-1]] % mod + 1) % mod;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            for(int k=1;k<=n;++k){
                if(k==i)
                    continue;
                for(int l=k;l<=n;++l)
                    ans[sumW[j]-sumW[i-1]+sumw[l]-sumw[k-1]] =  (ans[sumW[j]-sumW[i-1]+sumw[l]-sumw[k-1]] % mod + 1)%mod;
            }
        }
    }

  
    for(int i = 1;i <= m;++i)
        printf("%d ",ans[i]);
    printf("\n");   
    return 0;
}