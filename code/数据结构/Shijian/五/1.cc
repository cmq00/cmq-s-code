#include <bits/stdc++.h>

using namespace std;

#define MAXVERTEX 100

typedef int VertexType;
typedef int EdgeType;

bool vis[10004];

typedef struct
{
    VertexType vex[1004];
    int vexnum,arcnum;
    int arc[504][504];
}AMGraph;

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
    puts(" 输入顶点数和边数：");
    cin >> G.vexnum >> G.arcnum;
    puts("输入顶点：");
    for(int i = 1;i <= G.vexnum;++i){
        cin >> G.adjlist[i].data;
        G.adjlist[i].firstarc = NULL;
    }
    for(int k = 1;k <= G.arcnum;++k){
        VertexType u,v;
        cin >> u >> v;
        int i = LocatedVex(G,u);
        int j = LocatedVex(G,v);

        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        p = (EdgeNode*)malloc(sizeof(EdgeNode));
        p = G.adjlist[i].firstarc;
        if(p == NULL){
            G.adjlist[i].firstarc = e;
            e->adjvex = j;
        }
        else{
            while(p->nextarc != NULL){
                p = p->nextarc;
            }
            p->nextarc = e;
            e->adjvex = j;
        }
        
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        p = (EdgeNode*)malloc(sizeof(EdgeNode));
        p = G.adjlist[j].firstarc;
        if(p == NULL){
            G.adjlist[j].firstarc = e;
            e->adjvex = i;
        }
        else{
            while(p->nextarc != NULL){
                p = p->nextarc;
            }
            p->nextarc = e;
            e->adjvex = i;
        }
    }
}

void PrintAdjListGraph(ALGraph G,AMGraph &g)
{
    for(int i = 1;i <= G.vexnum;++i){
        EdgeNode *p = G.adjlist[i].firstarc;
        cout << G.adjlist[i].data;
        while(p){
            cout << "->" << p->adjvex;
            g.arc[i][p->adjvex] = 1;
            p = p->nextarc;
        }
        cout << endl;
    }
    cout << endl;
}

void PrintAMGraph(AMGraph g)
{
    for(int i = 1;i <= g.arcnum;++i){
        for(int j = 1;j <= g.arcnum;++j){
            cout << g.arc[i][j] << " ";
        }
        puts("");
    }
}

int main()
{
    ALGraph G;
    AMGraph g;
   
    InitQueue(Q);
    CreateAdjListGraph(G);
    g.vexnum = G.vexnum;
    g.arcnum = G.arcnum;

    puts("根据邻接表建立该图的邻接矩阵");
    puts("领接表：");
    PrintAdjListGraph(G,g);
    puts("领接矩阵：");
    PrintAMGraph(g);
}
