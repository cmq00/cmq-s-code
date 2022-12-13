#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f;
const int N = 110;
int maxx = -inf,minx = inf;
int range[] = {9,81,729,6561,59409,531441,4782969,43046721,387420489};
int a[N],n,m;

int mod(int x)
{
    return (x % 10 + 10) % 10;
}

void dfs(int dep,int now,int val)
{
    if(val >= minx && val*range[m - dep] <= maxx)   return ;
    int sum = 0;
    if(dep == m){
        for(int i = now;i <= n;++i)
            sum += a[i];
        minx = min(minx,val * mod(sum));
        maxx = max(maxx,val * mod(sum));
        return ;
    }
    for(int i = now;i <= (n - m + dep);++i){
        sum += a[i];
        dfs(dep + 1,i + 1,val * mod(sum));
    }

}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;++i){
        scanf("%d",&a[i]);
        a[i + n] = a[i];
    }
    for(int i = 1;i <= n;++i){
        dfs(1,1,1);
        for(int j = 1;j <= 2 * n;++j)   a[j] = a[j + 1];
    }
    printf("%d\n%d\n",minx,maxx);
    return 0;
}