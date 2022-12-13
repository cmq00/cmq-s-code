#include <bits/stdc++.h>

using namespace std;

#define MAXVERTEX 100

typedef char VertexType;
typedef int EdgeType;

bool vis[10004];
int dis[10004];
int maxx;
int ans;

typedef struct EdgeNode
{
    int adjvex;
    struct EdgeNode *nextarc;
    int w;
}EdgeNode;

typedef struct VNode
{
    VertexType data;
    EdgeNode *firstarc;
}VNode,AdjList[MAXVERTEX];

typedef struct
{
    AdjList adjlist;
    int vexnum,arcnum;
}ALGraph;

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

LinkQueue Q;

int InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    // if(!Q.front)
    //     exit(OVERFLOW);
    Q.front->next = NULL;
    return 1;
}

int QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return 1;
    return -1;
}

int EnQueue(LinkQueue &Q,VertexType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return 1;
}

int DeQueue(LinkQueue &Q,int &e)
{
    if(Q.front == Q.rear)
        return -1;
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p = Q.front;
    Q.front = Q.front->next;
    e = Q.front->data;
    free(p);
    return 1;
}

int LocatedVex(ALGraph G,int u)
{
    int i;
    for(i = 1;i <= G.vexnum;++i){
        if(u == G.adjlist[i].data)
            return i;
    }
    return -1;
}

void CreateAdjListGraph(ALGraph &G)
{
    EdgeNode *e,*p;
    //uts(" 输入顶点数和边数：");
    cin >> G.vexnum >> G.arcnum;
    //puts("输入顶点：");
    for(int i = 1;i <= G.vexnum;++i){
        cin >> G.adjlist[i].data;
        G.adjlist[i].firstarc = NULL;
        dis[i] = 0x3f3f3f3f;
    }
    for(int k = 1;k <= G.arcnum;++k){
        VertexType u,v;
        int w;
        cin >> u >> v >> w;
        int i = LocatedVex(G,u);
        int j = LocatedVex(G,v);

        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        p = (EdgeNode*)malloc(sizeof(EdgeNode));
        // e->adjvex = j;
        // e->nextarc = G.adjlist[i].firstarc;
        // G.adjlist[i].firstarc = e;
        p = G.adjlist[i].firstarc;
        if(p == NULL){
            G.adjlist[i].firstarc = e;
            e->adjvex = j;
            e->w = w;
        }
        else{
            while(p->nextarc != NULL){
                p = p->nextarc;
            }
            p->nextarc = e;
            e->adjvex = j;
            e->w = w;
        }
        
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        p = (EdgeNode*)malloc(sizeof(EdgeNode));
        // e->adjvex = i;
        // e->nextarc = G.adjlist[j].firstarc;
        // G.adjlist[j].firstarc = e;

        p = G.adjlist[j].firstarc;
        if(p == NULL){
            G.adjlist[j].firstarc = e;
            e->adjvex = i;
            e->w = w;
        }
        else{
            while(p->nextarc != NULL){
                p = p->nextarc;
            }
            p->nextarc = e;
            e->adjvex = i;
            e->w = w;
        }
    }
}

// void dfs(ALGraph G,VertexType u)
// {
//     cout << u << " ";
//     vis[u] = 1;
//     EdgeNode *p = G.adjlist[u].firstarc;
//     while(p != NULL){
//         int v = p->adjvex;
//         if(!vis[v])
//             dfs(G,v);
//         p = p->nextarc; 
//     }
// }

// void bfs(ALGraph G,int i)
// {
//     cout << G.adjlist[i].data;
//     vis[i] = 1;
//     EnQueue(Q,i);
//     while(QueueEmpty(Q) == -1){
//         int t;
//         DeQueue(Q,t);
//         EdgeNode *p = G.adjlist[t].firstarc;
//         while(p != NULL){
//             int j = p->adjvex;
//             if(!vis[j]){
//                 vis[j] = 1;
//                 cout << " " << G.adjlist[j].data;
//                 EnQueue(Q,j);
//             }
//             p = p->nextarc;
//         }
//     }

// }

void PrintAdjListGraph(ALGraph G)
{
    for(int i = 1;i <= G.vexnum;++i){
        EdgeNode *p = G.adjlist[i].firstarc;
        cout << G.adjlist[i].data;
        while(p){
            cout << "->" << p->adjvex;
            p = p->nextarc;
        }
        cout << endl;
    }
    cout << endl;
}

void dijkstra(ALGraph G, int s)
{
    while(vis[s] == 0){
        //cout << G.adjlist[s].data << endl;
        vis[s] = 1;
        int minn = 0x3f3f3f3f;
        EdgeNode *p = G.adjlist[s].firstarc;
        while(p){
            if(vis[p->adjvex] == 0 && p->w + dis[s] < dis[p->adjvex])
                dis[p->adjvex] = p->w + dis[s];
            //cout << p->adjvex << " " <<  p->w << " " << dis[p->adjvex] << endl;
            p = p->nextarc;
        }
        for(int i = 1;i <= G.vexnum;++i){
            if(dis[i] < minn && vis[i] == 0){
                minn = dis[i];
                s = i;
            }
        }
    }
}

int main()
{
    ALGraph G;
    InitQueue(Q);
    CreateAdjListGraph(G);
    //PrintAdjListGraph(G);
    int ans = 0x3f3f3f;
    char ch;
    for(int i = 1;i <= G.vexnum;++i){
        //cout << "now: " << i << endl;
        dis[i] = 0;
        int res = 0;
        dijkstra(G,i);
        for(int i = 1;i <= G.vexnum;++i)
            res = max(res,dis[i]);
        if(res < ans){
            ans = res;
            ch = G.adjlist[i].data;
        }
        for(int i = 1;i <= G.vexnum;++i){
            //cout << dis[i] << " ";
            dis[i] = 0x3f3f3f3f;
        }
        memset(vis,0,sizeof(vis));
    }
    cout << ch << endl;
}
// 4 5
// A B C D
// A B 8
// A D 6
// B C 4
// B D 5
// C D 3