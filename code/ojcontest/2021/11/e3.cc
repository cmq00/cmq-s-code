#include<bits/stdc++.h>
using namespace std;
char dp[105][105];
bool vis[105][105];
int ex[]={-2,-1,1,2,2,1,-1,-2};
int ey[]={-1,-2,-2,-1,1,2,2,1};
int e1[]={-1,0,0,1,1,0,0,-1};
int e2[]={0,-1,-1,0,0,1,1,0};
int fx,fy,sx,sy;
int judge,n,m,ans;
struct Point{
	int x,y;
	int step;
};
void bfs(){
	Point a;
	a.x=fx;a.y=fy;a.step=0;
	vis[fx][fy]=1;
	queue<Point>node;
	node.push(a);
	while(!node.empty()){
		Point temp;
		temp=node.front();
		node.pop();
		if(temp.x==sx&&temp.y==sy){
			judge=1;
			ans=temp.step;
			return;
		}
		for(int i=0;i<=7;i++){
			Point nex;
			nex.x=temp.x+ex[i];
			nex.y=temp.y+ey[i];
			if(vis[nex.x][nex.y]==0&&nex.x>=1&&nex.x<=n&&nex.y>=1&&nex.y<=m&&(dp[nex.x][nex.y]=='.'||dp[nex.x][nex.y]=='K')&&dp[temp.x+e1[i]][temp.y+e2[i]]=='.'){
				nex.step=temp.step+1;
				vis[nex.x][nex.y]=1;
				node.push(nex);
			}
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		judge=0;
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		n++;
		m++;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int z=1;z<=m;z++){
				cin>>dp[i][z];
				if(dp[i][z]=='S'){
					fx=i;
					fy=z;
				}
				if(dp[i][z]=='K'){
					sx=i;
					sy=z;
				}
				if(dp[i][z]=='M'){
					int x=i;
					int y=z;
					for(int j=1;j<=n;j++) vis[j][y]=1;
					for(int k=1;k<=m;k++) vis[x][k]=1;
				}
			}
		}
		bfs();
		if(judge==0) printf("-1\n");
		else printf("%d\n",ans);
	}
}