#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 4;
int step[N];
int vis[N];
int ans[N];
int n,s,t;

queue<int> q;
int bfs(int x)
{
    int hd,nt;
    q.push(x);
    step[x] = 0;
    while( !q.empty()){
        hd = q.front();
        q.pop();
        for(int i = s;i <= t;++i){
            nt = hd + i;

        }
    }
}

int main()
{
    int m;
    scanf("%d %d %d %d",&n,&s,&t,&m);
    while(m--){
        int x;
        scanf("%d",&x);
        vis[x] = 1;
    }
    printf("%d\n",bfs(0));
    return 0;
}