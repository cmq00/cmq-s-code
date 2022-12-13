/*
 * ÿһ��ͼʹ��3��ʽ��ͼ:
 * 1. �ڽӾ���(��Ӧ����dfs������dijkstra��floyd)
 * 2. ��ʽǰ����(��Ӧ���Ż�dijkstra)
 * 3. C++�Դ�vectorģ����ʽǰ����(��Ӧspfa)
 */
#include <bits/stdc++.h>
const int N = 1010;   //ͼ�����ڵ���
const int M = 100010; //ͼ��������
using namespace std;
//�ڽӱ�
int mp[N][N];

//��ʽǰ����
struct node
{
    int to, val;
    int nex;
};	
int head[N], k;
node edge[M];

// vectorģ����ʽǰ����
// pair<������һ����,Ȩֵ>
vector<pair<int, int> > E[N];

//--------------------//
int n, m; // n���㣬m����

int vis[N];
int dist[N];

void dfs(int u) //����֦dfs����
{
    vis[u] = true;
    for (int v = 1; v <= n; v++)
    {
        if (v == u || vis[v])
            continue;
        //��֦
        //���ͨ����ǰ����չ�󷽵��Ѿ�����һ����������Ľ⣬��ô�ò���չ
        if (dist[v] > dist[u] + mp[u][v])
        {
            dist[v] = dist[u] + mp[u][v];
            dfs(v);
        }
    }
    vis[u] = false;
}

void dijkstra(int s) //����dijkstra�㷨
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0x0, sizeof(vis));
    dist[s] = 0;
    for (int i = 1; i < n; i++)
    {
        int u = 0;
        for (int v = 1; v <= n; v++)
            if (!vis[v] && (u == 0 || dist[u] > dist[v]))
                u = v;
        vis[u] = true;
        for (int v = 1; v <= n; v++)
            dist[v] = min(dist[v], dist[u] + mp[u][v]);
    }
}

void dijkstra_heap(int s) //���Ż�dijkstra�㷨
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0x0, sizeof(vis));
    dist[s] = 0;
    priority_queue<pair<int, int> > q;
    q.push( {-0, s} );
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; i; i = edge[i].nex)
        {
            int v = edge[i].to;
            int d = edge[i].val;
            if (dist[v] > dist[u] + d)
            {
                dist[v] = dist[u] + d;
                q.push({-dist[v], v});
    :}
        }
    }
}

struct NODE
{
    int to;
    bool friend operator<(NODE a, NODE b)
    {
        return dist[a.to] > dist[b.to];
    }
};

void spfa(int s) //���Ż�spfa(�Ƕ����Ż�)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0x0, sizeof(vis));
    dist[s] = 0;
    priority_queue<NODE> q;
    q.push({s});
    vis[s] = true;
    while (!q.empty())
    {
        int u = q.top().to;
        q.pop();
        vis[u] = false;
        for (auto &&elm : E[u])
        {
            int v = elm.first;
            int d = elm.second;
            if (dist[v] <= dist[u] + d)
                continue;
            dist[v] = dist[u] + d;
            if (!vis[v])
            {
                vis[v] = true;
                q.push({v});
            }
        }
    }
}

void floyd() // floydȫ�����·
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
}

// solve( ��� , ģʽ )
void solve(int s = 1, int mode = 0)
{
    if (mode == 0)
    {
        dist[s] = 0;
        dfs(s);
        for (int i = 1; i <= n; i++)
            printf("%d ", dist[i]);
    }
    if (mode == 1)
    {
        dijkstra(s);
        for (int i = 1; i <= n; i++)
            printf("%d ", dist[i]);
    }
    if (mode == 2)
    {
        dijkstra_heap(s);
        for (int i = 1; i <= n; i++)
            printf("%d ", dist[i]);
    }
    if (mode == 3)
    {
        spfa(s);
        for (int i = 1; i <= n; i++)
            printf("%d ", dist[i]);
    }
    if (mode == 4)
    {
        floyd();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                printf("%d ", mp[i][j]);
            puts("");
        }
    }
    puts("");
}

void init()
{
    k = 0;
    memset(head, 0x0, sizeof(head));
    memset(edge, 0x0, sizeof(edge));
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0x0, sizeof(vis));
    memset(mp, 0x3f, sizeof(mp));
    for (int i = 1; i <= n; i++)
        mp[i][i] = 0, E[i].clear();
}

void add(int come, int to, int val)
{
    edge[++k] = {to, val, head[come]};
    head[come] = k;

    E[come].push_back({to, val});

    mp[come][to] = val;
}

int main()
{
    int s;
    scanf("%d%d%d", &n, &m, &s);
    init(); //��ʼ��
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        //ÿ�ν����ߣ�ȨֵΪw
        //˫�߾�������������
        add(u, v, w);
        add(v, u, w);
    }
    solve();
    return 0;
}

/*
6 9 3
1 2 2
2 4 1
1 3 5
3 4 3
1 4 4
3 6 9
3 5 5
5 6 2
2 5 6
*/
