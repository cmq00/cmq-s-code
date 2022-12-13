#include<iostream>
#include<stdio.h>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
int dis[4][2]={1,0,-1,0,0,1,0,-1};
struct node{
    int x,y,k;
}now,well;
queue<node>q;
int f[1010][1010],n,m,s,t,flash,mmmm;
char a[1010][1010];
int bfs(int k,int b,int n,int m)
{
    node A;
    A.x=k;
    A.y=b;
    A.k=0;
    q.push(A);
    f[A.x][A.y]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if((now.x==n||now.x==1||now.y==1||now.y==m) && a[now.x][now.y] == '.')
       {flash=0; return now.k;}
        for(int i=0;i<4;i++)
         { well.x=now.x+dis[i][0];
            well.y=now.y+dis[i][1];
            if(well.x>0&&well.x<=n&&well.y>0&&well.y<=m&&f[well.x][well.y]==0&&a[well.x][well.y]=='.')
            {
                f[well.x][well.y]=1;
                well.k=now.k+1;
                q.push(well);
                
            }
            }
    }
}
int main()
{int t;
    cin>>t;
    while(t--)
    {flash=1;
        cin>>n>>m;
        cin>>s>>t;
     for(int i=1;i<=n;i++)
    {for(int j=1;j<=m;j++)
    {
        cin>>a[i][j];
    }}mmmm=bfs(s,t,n,m);
    if(flash==0)
   cout<<mmmm<<endl;
    else cout<<-1<<endl;
     memset(f,0,sizeof(f));
    memset(a,0,sizeof(a));
    while(!q.empty())
    {
        q.pop();
    }}
   return 0;
}