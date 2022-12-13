#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;
int n,m,s,t,tol,flag,anss;
int step[N][N];
int ans[N];
/*struct Node
{
    int d;
};*/

vector<int> V[N];
queue<int> q;

int bfs(int x)
{
    anss = step[s][t];
    //printf("anss:%d\n",anss);
    int head,next;
    q.push(x);
    //step[x][V[x][0]] = 1;
    while(!q.empty()){
        head = q.front();
        q.pop();
        for(int i = 0;i < V[head].size();++i){
            next = V[head][i];
            //if(!vis[next]){
                //vis[next] = 1;
                 //printf("step[%d][%d]:%d\n",head,next,step[head][next]);
                ans[next] = ans[head] + step[head][next];
                q.push(next);
            //}
            if(next == t){
                flag = 1;
                //printf("ans[%d][%d]:%d\n",s,next,ans[s][next]);
                anss = min(ans[next],anss);
                //printf("anss:%d\n",anss);    
            }
                      
        }
    }
    if(flag == 0)
        return -1;
    return anss;
}

int main()
{
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i = 0;i < m;++i){
        int x,l,y;
        scanf("%d %d %d",&x,&y,&l);
        V[x].push_back(y);
        step[x][y] = l;
    }

    printf("%d\n",bfs(s));
    return 0;
}