#include <bits/stdc++.h>

using namespace std;

struct node
{
    int vis;
    int time;
}game[2000];

bool cmp(node a,node b)
{
    return a.time < b.time;
}

int main()
{
    int n,m,k,ans = 0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1;i <= n;++i){
        scanf("%d",&game[i].time);
        game[i].vis = 1;
    }
    for(int i = 1;i <= m;++i){
        int t;
        scanf("%d",&t);
        ans += game[t].time;
        game[t].vis = 0;
    }
    int cont = 0;
    sort(game + 1,game + n + 1,cmp);
    //for(int i = 1;i <= n;++i)
        //printf("%d ",game[i].time);
    //cout << endl;
    for(int i = 1;i <= n;++i){
        if(game[i].vis){
            ans += game[i].time;
            cont++;
            if(cont == k - m)
            break;
        }
        
    }
    printf("%d\n",ans);
    return 0;
}