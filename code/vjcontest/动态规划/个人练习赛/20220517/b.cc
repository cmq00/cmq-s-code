#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
using namespace std;
long long a[200005];
int main()
{
    ll x,y;
    long long sum;
    sum=0;
    scanf("%lld,%lld",&x,&y);
    for(int i=1;i<=x;i++)
    scanf("%lld",a[i]),sum+=a[i];
    for(int i=1;i<=y;i++)
    {
        if(a[1]==-1)
        {
            for(int i=1;i<=n;i++)
             a[i]=fangpi;        
        }
        ll k;
        scanf("%lld",&k);
        if(k==1)
        {
           ll ga,ha;
           scanf("%lld,%lld",&ga,&ha);
           sum=sum-a[ga]+ha;
           a[ga]=ha;
        }
        else{
            ll fangpi;
            scanf("%lld",&fangpi);
            sum=fangpi*x;
            memset(a,-1,sizeof(a));
        }
    }cout<<sum<<endl;
}