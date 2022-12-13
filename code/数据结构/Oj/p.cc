#include <bits/stdc++.h>

using namespace std;

typedef int VertexType;

typedef struct
{
    VertexType vex[1004];
    int vexnum,arcnum;
    int arc[504][504];
}AMGraph;

typedef struct
{
    int u,v;
    int w;
}Kedge;

int f[1004];
Kedge k[1004];
int ans;

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
    cin >> G.vexnum >> G.arcnum;
    for(int i = 1;i <= G.vexnum;++i)
        cin >> G.vex[i];
    for(int i = 1;i <= G.arcnum;++i){
        for(int j = 1;j <= G.arcnum;++j)
            G.arc[i][j] = 0x3f3f3f3f;
    }
    for(int p = 1;p <= G.arcnum;++p){
        VertexType u,v;
        int i,j,w;
        cin >> u >> v >> w;
        i = Locatevex(G,u);
        j = Locatevex(G,v);
        G.arc[i][j] = w;
        G.arc[j][i] = w;
        k[p].u = i;
        k[p].v = j;
        k[p].w = w;
    }
}

void Quick_Sort(Kedge *k,int begin,int end)
{
    if(begin > end)
        return ;
    Kedge t = k[begin];
    int i = begin;
    int j = end;
    while(i != j){
        while(k[j].w >= t.w && j > i)
            j--;
        while(k[i].w <= t.w && j > i)
            i++;
        if(j > i){
            Kedge tt = k[i];
            k[i] = k[j];
            k[j] = tt;
        }
    }
    k[begin] = k[i];
    k[i] = t;
    Quick_Sort(k,begin,i - 1);
    Quick_Sort(k,i + 1,end);
}

void Kruskal(AMGraph G)
{
    
    for(int i = 1;i <= G.vexnum;++i)
        f[i] = i;
    Quick_Sort(k,1,G.arcnum);
    Kedge temp;
    // for(int i = 1;i <= G.arcnum;i++){ 
 //  for(int j = 1;j <= G.arcnum - i;j++){
 //    if(k[j].w > k[j+1].w){
 //     temp = k[j+1];
 //     k[j+1] = k[j];
 //     k[j] = temp;
    //             }
    //     }
    // }

    for(int i = 1;i <= G.vexnum;++i){
        int s1 = f[k[i].u];
        int s2 = f[k[i].v];
        if(s1 != s2){
            ans += k[i].w;
            f[k[i].v] = s1;
            for(int i = 1;i <= G.vexnum;++i){
                if(f[i] == s2){
                    f[i] = s1;
                }
            }
        }
    }
}

int main()
{
    AMGraph G;
    CreateGraph(G);
    // for(int i = 1;i <= G.arcnum;++i){
    //     cout << k[i].u << " " << k[i].v << " " << k[i].w << endl;
    // }
    Kruskal(G);
    // for(int i = 1;i <= G.arcnum;++i){
    //     cout << k[i].u << " " << k[i].v << " " << k[i].w << endl;
    // }
    cout << ans << endl;
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