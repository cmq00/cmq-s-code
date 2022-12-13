#include <bits/stdc++.h>

using namespace std;

int fun1(int x)
{
    int ans = 1;
    for(int i = 1;i <= x;++i)
        ans *= i;
    return ans;
}

int fun2(int x,int y)
{
    int ans = 1;
    for(int i = x;i > x - y;--i)
        ans *= i;
    return ans;
}

int main()
{
   int t;
   scanf("%d",&t);
   //int a[12];
   //for(int i = 1;i <= 12;++i)
        //a[i] = fun(i);
        //for(int i = 1;i <= 12;++i)
            //printf("%d ",a[i]);
   while(t--){
       int ans = 0;
       int n;
       scanf("%d",&n);
    
       int k = fun1(n - 1);
       //printf("k:%d\n",k);
       for(int i = n;i <= 2 * n - 2;++i){
           //printf("i:%d,n:%d\n",i,n - 1);
       //printf("fun2:%d\n",fun2(i,n - 1));

            ans += fun2(i,n - 1) / k;
       }
        printf("%d\n",ans + 1);
   }
    return 0;
}