#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e7 + 4;
ll a[N],b[N];

int main()
{
    ll i,j;
    for(i = 1; i <= N;++i){
        for(j = 1;j <= N / i;++j){
            a[i * j] += i;
        }
    }
    //cout << a[1] << a[2] << endl;
    //return 0;
    for(i = 1;i <= N;++i){
        if(a[i] > N)   continue;
        else{
            if(b[a[i]] == 0)
                b[a[i]] = i;
            else
                b[a[i]] = min(b[a[i]],i);
        }
    }

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(b[n])
            printf("%lld\n",b[n]);
        else
            printf("-1\n");
    }
    return 0;
}