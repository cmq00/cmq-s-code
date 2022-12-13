#include <bits/stdc++.h>

using namespace std;

struct prob
{
    int num;
    int able;
};

bool cmp(prob x,prob y)
{
    return x.able < y.able;
}

int fun(prob arr[],int n)
{
    int maxx = arr[0].able,inc = arr[0].num;
    for(int i = 1;i < n;++i){
        maxx = max(arr[i].able - inc,maxx);
        inc += arr[i].num;
    }
    return maxx;
}

int main()
{
    int t;
    prob conset[10001];
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);

        for(int j = 0;j < n;++j){
            int m;
            scanf("%d",&m);

            prob problem[14];
            for(int  i = 0;i < m;++i){
                scanf("%d",&problem[i].able);
                problem[i].num = 1;
            }
            conset[j].able = fun(problem,m) + 1;
            conset[j].num = m;
        }

        sort(conset,conset + n,cmp);
        int ans = fun(conset,n);
        printf("%d\n",ans);
    }
    return 0;
}
            
