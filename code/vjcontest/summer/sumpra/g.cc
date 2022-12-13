#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
int n;
int c[2000000];
struct node
{
    int x;
    int id;
}a[2000000];
bool cmp(node x,node y)
{
    return x.x<y.x;
}
int mp[2000000];
int ls[2000000];
int lb[2000000];
long long rs[2000000];
int lowbit(int x)
{
     return x&(-x);
}
int Sum(int n)
{
    int sum=0;
    while(n>0)
    {
            sum+=c[n];
         n=n-lowbit(n);
    }
    return sum;
}
void change(int i,int x)
{
     while(i<=n)
     {
          c[i]=c[i]+x;
          i=i+lowbit(i);
     }
}
int main()
{
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].x);
            a[i].id=i;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++) mp[a[i].id]=i;
 
        for(int i=1;i<=n;i++)
        {
            change(mp[i],1);
            ls[mp[i]]=Sum(mp[i])-1;
            lb[mp[i]]=i-ls[mp[i]]-1;
        }
        long long ans=0;
//        for(int i=1;i<=n;i++)
//        {
//            printf("%d ",lb[mp[i]]);
//        }
//        puts("");
//        for(int i=1;i<=n;i++)
//        {
//            printf("%d ",ls[mp[i]]);
//        }
        for(int i=1;i<=n;i++)
        {
            rs[mp[i]]=(mp[i]-1-ls[mp[i]]);
            ans+=rs[mp[i]]*lb[mp[i]];
        }
        cout<<ans<<endl;
    return 0;
}

