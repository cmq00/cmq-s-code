#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int fa[N],val[N];

int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        int p = find(fa[x]);
        val[x] += val[fa[x]];
        return fa[x] = p;
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n)){
    for(int i = 0;i <= n;++i){
        fa[i] = i;
        val[i] = 0;
    }
    while(n--){
        int op,a,b,m;
        scanf("%d",&op);
        if(op == 1){
             scanf("%d %d %d",&a,&b,&m);
             int A = find(a),B = find(b);
             if(A != B){
                 fa[B] = A;
                 val[B] = val[a] + m - val[b];
             }
        }
        else{
            int aa,bb;
            scanf("%d %d",&aa,&bb);
            int AA = find(aa),BB = find(bb);
            if(AA != BB)  
                printf("?\n");
            else   
                printf("%d\n",val[bb] - val[aa]);
        }

    }
    }
    return 0;
}