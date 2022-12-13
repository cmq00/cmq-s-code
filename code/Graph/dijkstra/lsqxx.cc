#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6 + 4;
int head[20004];
ll ans[20004];
bool vis[20004];
int n,m,s,cnt;

struct Node
{
	int to;
	int next;
	int w;
}edge[N];

void add_edge(int u,int v,int w)
{
	cnt++;
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

void dijkstra()
{
	int pos = s;
	while(vis[pos] == 0){
		vis[pos] = 1;
		ll minn = 2147483647; 
		for(int i = head[pos];i != 0;i = edge[i].next){
			if(edge[i].w + ans[pos] < ans[edge[i].to] && vis[edge[i].to] == 0)
				ans[edge[i].to] = edge[i].w + ans[pos];
		}			
		for(int i = 1;i <= n;++i){
			if(ans[i] < minn && vis[i] == 0){
				minn = ans[i];
				pos = i;
			}
		}
	}
}

int  main()
{
	cin >> n >> m >> s;
	for(int i = 1;i <= n;++i){
			ans[i] = 2147483647;
	}
	ans[s] = 0;
	int u,v,w;
	for(int i = 1;i <= m;++i){
		cin >> u >> v >> w;
		add_edge(u,v,w);
	}
	dijkstra();
	for(int i = 1;i <= n;++i){
		cout << ans[i] << " ";
	}
	puts("");
	return 0;
}

