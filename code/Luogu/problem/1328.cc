#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,na[210],nb[210];
    int a,b;
    scanf("%d %d %d",&n,&a,&b);
    for(int i = 1;i <= a;++i)
        scanf("%d",&na[i]);
    for(int i = a + 1;i <= n;++i)
        na[i] = na[i - a];

    for(int i = 1;i <= b;++i)
        scanf("%d",&nb[i]);
    for(int i = b + 1;i <= n;++i)
        nb[i] = nb[i - b];
    /*for(int i = 1;i <= n;++i)
        printf("%d ",na[i]);
    printf("\n");
    for(int i = 1;i <= n;++i)
        printf("%d ",nb[i]);
    printf("\n");*/
    int ansa,ansb;
    ansa = ansb = 0;
    for(int i = 1;i <= n;++i){
        if(na[i] == 0){
            if(nb[i] == 2 || nb[i] == 3)
                ansa++;
            else if(nb[i] == 1 || nb[i] == 4)
                ansb++;
        }
        if(na[i] == 1){
            if(nb[i] == 0 || nb[i] == 3)
                ansa++;
            else if(nb[i] == 2 || nb[i] == 4)
                ansb++;
        }
        if(na[i] == 2){
            if(nb[i] == 4 || nb[i] == 1)
                ansa++;
            else if(nb[i] == 0 || nb[i] == 3)
                ansb++;
        }
        if(na[i] == 3){
            if(nb[i] == 4 || nb[i] == 2)
                ansa++;
            else if(nb[i] == 0 || nb[i] == 1)
                ansb++;
        }
        if(na[i] == 4){
            if(nb[i] == 0 || nb[i] == 1)
                ansa++;
            else if(nb[i] == 2 || nb[i] == 3)
                ansb++;
        }
    }
    printf("%d %d\n",ansa,ansb);
    return 0;
}