#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int vis[N],step[N];
queue<int> q;

int bfs(int n,int k)
{
    int head,next;
    q.push(n);
    step[n] = 0;
    vis[n] = true;
    while(!q.empty()){
        head = q.front();
        q.pop();
        for(int i = 1;i <= 3;++i){
            if(i == 1)
                next = head - 1;
            else if(i == 2)
                next = head + 1;
            else
                next = 2 * head;
            if(next < 0 || next > N)
                continue;
            if(!vis[next]){
                vis[next] = true;
                step[next] = step[head] + 1;
                q.push(next);
            }
            if(next == k)
                return step[next];
        }
    }
}

int main()
{
    int n,k;
    while(~scanf("%d %d",&n,&k)){
        memset(step,0,sizeof(step));
        memset(vis,0,sizeof(vis));
        while(!q.empty())
            q.pop();

        if(n >= k)
            printf("%d\n",n - k);
        else
            printf("%d\n",bfs(n,k));
    }
    return 0;
}
        