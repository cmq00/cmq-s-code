#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int mage[1010][2];
int vis[1010][1010];
int dir[4][2]={0,1,1,0,0,-1,-1,0};//一直
int dirr[4][2][2]={1,1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1};//一斜
int n,m,T;

void bfs()
{
    queue<pair<int,int> >q;
    q.push(make_pair(n,0));
    vis[n][0]=0;
    while(q.size())
    {
        pair<int,int> st=q.front();

         pair<int,int> nt;
        q.pop();
        for(int i=0;i<4;i++)
        {
            nt.first=st.first+dir[i][0];
            nt.second=st.second+dir[i][1];
            if(nt.first>=0&&nt.first<=n&&nt.second>=0&&nt.second<=m&&a[nt.first][nt.second]=='.')
            {
                pair<int,int> ntt;
                for(int j=0;j<2;j++)
                {
                    ntt.first=nt.first+dirr[i][j][0];
                    ntt.second=nt.second+dirr[i][j][1];
                    if(ntt.first>=0&&ntt.first<=n&&ntt.second>=0&&ntt.second<=m
                       &&(a[ntt.first][ntt.second]=='.'||a[ntt.first][ntt.second]=='K')
                       &&vis[ntt.first][ntt.second]==-1
                       &&mage[ntt.first][0]==0&&mage[ntt.second][1]==0)
                        {
                            //printf("%d %d>>%d %d\n",st.first,st.second,ntt.first,ntt.second);
                            q.push(ntt);
                            vis[ntt.first][ntt.second]=vis[st.first][st.second]+1;}
                }


            }
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                vis[i][j]=-1;
            }
            mage[i][0]=0;
        }
        for(int i=0;i<=m;i++)
        mage[i][1]=0;

        pair<int,int>ed;
        for(int i=0; i<=n; i++)
        {
            getchar();
            for(int j=0; j<=m; j++)
            {
                scanf("%c",&a[i][j]);
                if(a[i][j]=='M')
                    mage[i][0]=1,mage[j][1]=1;
                if(a[i][j]=='K')
                    ed.first=i,ed.second=j;
            }

        }


        bfs();
        printf("%d\n",vis[ed.first][ed.second]);
    }


}
