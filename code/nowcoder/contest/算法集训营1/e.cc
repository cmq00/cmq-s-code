#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,tim = 0;
        scanf("%d %d",&n,&m);
        //assert(m < 1);
        if(m == 1)
            if(n == 1)
                tim = 1;
            else
                tim = -1;
        else if(n == m)
            tim = 1;
        else{
            tim = 2 + ((n - m) / (m - 1) + ((n - m) % (m - 1)!= 0)) * 2 - 1;
        }
        printf("%d\n",tim);
    }
    return 0;
}