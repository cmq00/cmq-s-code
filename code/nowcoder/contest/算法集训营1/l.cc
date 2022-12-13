#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char dir[10000];
        double ans = 0;
        int x = 0,y = 0;
        for(int i = 1;i <= n;++i){
            cin >> dir[i];
            if(dir[i] == 'L')
                x--;
            if(dir[i] == 'R')
                x++;
            if(dir[i] == 'U')
                y++;
            if(dir[i] == 'D')
                y--;
            double res = sqrt(x * x + y * y);
            ans = max(ans,res);
        }
        printf("%.12lf\n",ans);
    }
    return 0;
}