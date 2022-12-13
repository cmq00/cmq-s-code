#include <bits/stdc++.h>

using namespace std;

#define MAXVERTEX 100

typedef int VertexType;
typedef int EdgeType;

bool vis[10004];
int ve[1004],vl[1004],in[1004];
int ans = 0;


typedef struct EdgeNode
{
    int adjvex;
    struct EdgeNode *nextarc;
    int w;
    bool f;
}EdgeNode;

typedef struct VNode
{
    VertexType data;
    int step;
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


typedef struct 
{
    int *base;
    int *top;
    int stacksize;
}Stack;

Stack S,T;

int InitStack(Stack &s)
{
    s.base = (int *)malloc(1004 * sizeof(int));
    if(!s.base)
        return -1;
    s.top = s.base;
    s.stacksize = 1004;
    return 1;
}

int StackEmpty(Stack s)
{
    if(s.top == s.base)
        return 1;
    return -1;
}

int GetTop(Stack &s,int &e)
{
    if(s.top == s.base)
        return -1;
    e = *(s.top - 1);
    return 1;
}

int Push(Stack &s,int e)
{
    if(s.top - s.base > 1004){
        s.base = (int *)realloc(s.base,1004 * sizeof(int));
        s.stacksize += 10;
        s.top = s.base + 10;
    }
    *(s.top) = e;
    s.top++;
    return 1;
}

int Pop(Stack &s,int &e)
{
    if(s.base == s.top)
        return -1;
    s.top--;
    e = *(s.top);
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
    }
    for(int k = 1;k <= G.arcnum;++k){
        VertexType u,v;
        int w;
        cin >> u >> v >> w;
        int i = LocatedVex(G,u);
        int j = LocatedVex(G,v);
        in[j]++;

        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        p = (EdgeNode*)malloc(sizeof(EdgeNode));
        p = G.adjlist[i].firstarc;
        if(p == NULL){
            G.adjlist[i].firstarc = e;
            e->adjvex = j;
            e->w = w;
            e->f = 0;
        }
        else{
            while(p->nextarc != NULL){
                p = p->nextarc;
            }
            p->nextarc = e;
            e->adjvex = j;
            e->w = w;
            e->f = 0;
        }
    }
        
}

int TopologicalOrder(ALGraph G,Stack &T)
{
    int cnt = 0;
    Push(S,1);
    while(StackEmpty(S) == -1){
        int u;
        Pop(S,u);
        Push(T,u);
        ++cnt;
        EdgeNode* p = G.adjlist[u].firstarc;
        while(p){
            int v = p->adjvex;
            in[v]--;
            if(in[v] == 0)
                Push(S,v);
            if(ve[u] + p->w > ve[v])
                ve[v] = ve[u] + p->w;
            p = p->nextarc;
        }
    }
    if(cnt < G.vexnum)
        return -1;
    return 1;
}

int CriticalPath(ALGraph G)
{
    for(int i = 1;i <= G.vexnum;++i){
        vl[i] = 0x3f3f3f3f;
    }
    vl[G.vexnum] = ve[G.vexnum];
    while(StackEmpty(T) == -1){
        int u;
        Pop(T,u);
        EdgeNode* p = G.adjlist[u].firstarc;
        while(p){
            int v;
            v = p->adjvex;
            if(vl[v] - (p->w) < vl[u])
                vl[u] = vl[v] - (p->w);
            p = p->nextarc;
        }
    }
    for(int i = 1;i <= G.vexnum;++i){
        EdgeNode* p = G.adjlist[i].firstarc;
        while(p){
            int ee,el;
            int v;
            v = p->adjvex;
            ee = ve[i];
            el = vl[v] - p->w;
            if(ee == el){
                p->f = 1;
            }
            p = p->nextarc;
        } 
    }
    return 1;
}


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

void dfs(ALGraph &G,int u)
{
    EdgeNode *p = G.adjlist[u].firstarc;
    while(p != NULL){
        int v = p->adjvex;
        if(p->f == 1){
            G.adjlist[v].step = min(G.adjlist[u].step + p->w,G.adjlist[v].step);
            dfs(G,v);
        }
        p = p->nextarc; 
    }
}

int main()
{
    ALGraph G;
    InitStack(S);
    InitStack(T);
    CreateAdjListGraph(G);
    TopologicalOrder(G,T);
    //PrintAdjListGraph(G);
    CriticalPath(G);
    for(int i = 1;i <= G.vexnum;++i){
        cout << ve[i] << " ";
    }
    puts("");
    for(int i = 1;i <= G.vexnum;++i){
        cout << vl[i] << " ";
    }
    puts("");
    for(int i = 1;i <= G.vexnum;++i)
        G.adjlist[i].step = 0x3f3f3f3f;
    G.adjlist[1].step = 0;
    dfs(G,1);
    cout << G.adjlist[G.vexnum].step << endl;
    return 0;
}
// 9 12
// A B C D E F G H M
// A B 3
// A C 10
// B D 9
// B E 13
// C E 12
// C F 7
// D G 8
// D H 4
// E H 6
// F H 11
// G M 2
// H M 5
