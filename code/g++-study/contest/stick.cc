#include <cstdio>

using namespace std;

int a[100004],n,m;

/*int check(int mid)
{
    int sum;
    for(int i = 0;i < n;++i)
        sum += a[i] / mid;
    if(sum >= m)
        return 1;
    else
        return 0;
}*/

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {   
        int i,maxa = 0,ans;
        scanf("%d %d",&n,&m);

        for(i = 0; i < n;++i)
        {
            scanf("%d",&a[i]);
            if(a[i] > maxa)
                maxa = a[i];
        }

    int sum = 0,j;

        for(j = 0;j < maxa;++j)
        {
            for(i = 0;i < n;++i)
            {
                sum += (a[i] - 1) / j;
            }
            ans = j;
        }


                

        /*int l = 0,r = maxa,mid,ans;

        while(l < r)
        {
            mid = (l + r) / 2;
            printf("l:%d r:%d mid:%d\n",l,r,mid);
            if(check(mid))
            {
                ans = mid;
                l = mid + 1;

            }
            else
                r = mid - 1;
        }*/
        printf("%d\n",ans);
    }
    return 0;
}
                

