#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;
int a[N],lmax[N],rmax[N],lmin[N],rmin[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]);
    stack<int> s1;
    stack<int> s2;
    for(int i = n;i >= 1;--i){
        while(!s1.empty() && a[s1.top()] <= a[i])
            s1.pop();
        while(!s2.empty() && a[s2.top()] >= a[i])
            s2.pop();
        if(s1.empty())
            rmax[i] = 0;
        else
            rmax[i] = s1.top();
        if(s2.empty())
            rmin[i] = 0;
        else
            rmin[i] = s2.top();
        s1.push(i);
        s2.push(i);
    }
    while(!s1.empty())
        s1.pop();
    while(!s2.empty())
        s2.pop();
     for(int i = 1;i <= n;++i){
        while(!s1.empty() && a[s1.top()] <= a[i])
            s1.pop();
        while(!s2.empty() && a[s2.top()] >= a[i])
            s2.pop();
        if(s1.empty())
            lmax[i] = 0;
        else
            lmax[i] = s1.top();
        if(s2.empty())
            lmin[i] = 0;
        else
            lmin[i] = s2.top();
        s1.push(i);
        s2.push(i);
    }

    printf("rmax: :");
    for(int i = 1;i <= n;++i)
        printf("%d ",rmax[i]);
    printf("\n");
    printf("lmax: :");
     for(int i = 1;i <= n;++i)
        printf("%d ",lmax[i]);
    printf("\n");
    printf("rmin: :");
     for(int i = 1;i <= n;++i)
        printf("%d ",rmin[i]);
    printf("\n");
    printf("lmin: :");
     for(int i = 1;i <= n;++i)
        printf("%d ",lmin[i]);
    printf("\n");

    int ans = 0;
    for(int i = 1;i <= n;++i){
        if(lmax[i] != 0)
            ans += a[lmax[i]] - a[i];
        if(rmax[i] != 0)
            ans += a[rmax[i]] - a[i];
        if(lmin[i] != 0)
            ans += a[i] - a[lmin[i]];
        if(rmin[i] != 0)
            ans += a[i] - a[rmin[i]];
    }
    printf("%d\n",ans);
    return 0;
}