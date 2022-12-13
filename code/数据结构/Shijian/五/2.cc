#include <bits/stdc++.h>

using namespace std;

typedef int VertexType;

typedef struct
{
    VertexType vex[1004];
    int vexnum,arcnum;
    int arc[504][504];
}AMGraph;

int vis[1004];


int Locatevex(AMGraph G,VertexType u)
{
    for(int i = 1;i <= G.vexnum;++i){
        if(G.vex[i] == u)
            return i;
    }
    return -1;
}

void CreateGraph(AMGraph &G)
{
    puts("输入顶点数和边数：");
    cin >> G.vexnum >> G.arcnum;
    puts("输入顶点：");
    for(int i = 1;i <= G.vexnum;++i)
        cin >> G.vex[i];
    for(int i = 1;i <= G.arcnum;++i){
        for(int j = 1;j <= G.arcnum;++j)
            G.arc[i][j] = 0x3f3f3f3f;
    }
    for(int p = 1;p <= G.arcnum;++p){
        VertexType u,v;
        int i,j;
        cin >> u >> v;
        i = Locatevex(G,u);
        j = Locatevex(G,v);
        G.arc[i][j] = 1;
        G.arc[j][i] = 1;
    }
}

void dfs(AMGraph G,int u)
{
    cout << G.vex[u] << " ";
    vis[u] = 1;
    for(int j = 1;j <= G.arcnum;++j){
        if(G.arc[u][j] == 1 && !vis[j]){
            dfs(G,j);
        }
    }
}

int main()
{
    AMGraph G;
    CreateGraph(G);
    puts("dfs:");
    dfs(G,1);
    puts("");
}
// 5 7
// A B C D E
// A B 10
// A C 8
// A E 3
// B C 2
// B D 5
// C E 7
// D E 4
