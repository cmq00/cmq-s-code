#include <bits/stdc++.h>

using namespace std;

struct Node{
    char name[1000];
    int score;
}node[10000];

bool cmp(Node x,Node y){
    return x.score > y.score;
}

int main()
{
    int i,t,n;
    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);
        for(i = 1;i <= n;++i)
            scanf("%s %d",node[i].name,&node[i].score);

        sort(node + 1,node + n  +1,cmp);
        //for(i = 1;i <= n;++i)
            //printf("%s %d\n",node[i].name,node[i].score);

        int count = 0;
        for(i = 1;i <= n;++i){
            if(i % 3 == 0){
                if((node[i].score + node[i - 1].score + node[i - 2].score) / 3 >= 1600)
                    count++;
                else break;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
