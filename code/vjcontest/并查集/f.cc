#include <cstdio>

using namespace std;

const int N = 30010;
int fa[N];

int find(int x)
{
    if(x == fa[x])
        return x;
    else
        return fa[x] = find(fa[x]);

}

int main()
{
    int stu[N];
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        if(n == 0 && m == 0)
            break;
        
        for(int i = 0;i <= N;++i)
            fa[i] = i;

        int ans = 0;
        for(int i = 1;i <= m;++i){
            int k;
            scanf("%d",&k);
            for(int j = 1;j <= k;++j){
                scanf("%d",&stu[j]);
                if(j > 1){
                    int x = find(stu[j - 1]),y = find(stu[j]);
                        fa[x] = y;
                } 
            }
        }
        for(int i = 0;i < n;++i)
            if(find(i) == find(0))
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}