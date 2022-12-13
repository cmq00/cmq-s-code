#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int from, to, dist;
	Edge (int _from, int _to, int _dist):from(_from), to(_to), dist(_dist){}
};
	
struct node{
    int d, u;
    node (int _d, int _u):d(_d), u(_u){}
    bool operator < (const node& rhs) const {
        return d > rhs.d;
    } 
};

const int maxn = 1e4 + 10;
const int INF=0x3f3f3f3f;// 正无穷 

class Dijkstra {
	int n, m;
	vector <Edge> edges;
	vector <int> g[maxn];	// 节点 i 的第 j 条边在 edges 中的编号 
	bool vis[maxn];			//标志位
	int dis[maxn];
	//int p[maxn]; 

public:
	void init(int n)
	{
		this -> n = n;
		for(int i = 0;i <= n;i ++)
			g[i].clear();
		edges.clear();
	}
	
	void addEdge(int from, int to, int dist)
	{
		edges.push_back(Edge(from, to, dist));
		/*edges.push_back(Edge(to, from, dist));
		g[from].push_back(edges.size() - 2);*/
		g[from].push_back(edges.size() - 1);
	}

	int dijkstra(int s, int t) // 从 s --> t 的最短路 
	{
		priority_queue <node> q;
		for(int i = 0;i <= n;i ++)	
			dis[i] = INF;
		memset(vis, false, sizeof(vis));
		dis[s] = 0;
		q.push(node(0, s));
		while(!q.empty())
		{
			node x = q.top(); q.pop();
			int u = x.u;
			if(vis[u])
				continue;
			vis[u] = true;
			for(int i = 0;i < g[u].size();i ++)
			{
				Edge& e = edges[g[u][i]];
				if(dis[e.to] > dis[u] + e.dist)
				{
					dis[e.to] = dis[u] + e.dist;
					//p[e.to] = g[u][i];
					q.push(node(dis[e.to], e.to));
				}
			}
		}
		return dis[t];
	}
	
};


int main()
{
    int n, m, s, t;
    scanf("%d %d %d %d",&n,&m,&s,&t);
    Dijkstra dijkstra;

    dijkstra.init(n);
    for(int i = 0;i < m;++i){
        int x,l,y;
        scanf("%d %d %d",&x,&y,&l);

        dijkstra.addEdge(x, y, l);
    }

    printf("%d\n", dijkstra.dijkstra(s, t));
    return 0;
}
