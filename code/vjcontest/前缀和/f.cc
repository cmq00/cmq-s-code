#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int main()
{
    int num[N];
    int ans[N];
    int n;
    scanf("%d",&n);
    //out << n << endl;
    for(int i = 1;i <= n;++i){
        scanf("%d",&num[i]);
        ans[i] = ans[i - 1] ^ num[i];
    } 
    int m;
    scanf("%d",&m);
    while(m--){
        int l,r;
        scanf("%d %d",&l,&r);
        //if(l == r)
            //printf("%d\n",num[l]);
        //else
            printf("%d\n",ans[l - 1] ^ ans[r]);
    }
    return 0;
}