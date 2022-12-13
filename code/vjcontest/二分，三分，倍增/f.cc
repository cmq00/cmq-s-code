//#include <bits/stdc++.h>
#include <cmath>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 5e4 + 5;
int n,q,a[N],f[N][30],g[N][30];//f[i][j]表示从i开始，长度为pow（2，j）的区间最大值，即[i,i + pow(2,j) - 1];

void prework(){
    //int t = log(n) / log(2) + 1;
    for(int j = 1;(1 << j) <= n;++j){
        for(int i = 1;i <= n - (1 << j) + 1;++i){
            f[i][j] = max(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
            g[i][j] = min(g[i][j - 1],g[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l,int r){
    int k = log(r - l + 1) / log(2);
    return max(f[l][k],f[r - (1 << k) + 1][k]) - min(g[l][k],g[r - (1 << k) + 1][k]);
}

/*int getmin(int l,int r){

    int k = log(r - l + 1) / log(2);
    return min(g[l][k],g[r - (1 << k) + 1][k]);
}*/
int main()
{
    //ios_base::sync_with_stdio(0);
    scanf("%d %d",&n,&q);
    for(int i = 1;i <= n;++i){
        scanf("%d",&a[i]);
        f[i][0] = g[i][0] = a[i];
    }
    prework();
    //int t = log(n) / log(2) + 1;
    //cout << "t:" << t << endl;
    /*for(int j = 1;j <= t;++j)
        for(int i = 1;i <= n - (1 << j) + 1;++i)
            printf("f[%d][%d]:%d\n",i,j,f[i][j]);*/
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return 0;
}