#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
struct Node
{
    int pre,re;
}p[N];

int find(int x)
{
    int t;
    if(x == p[x].pre)
        return x;
    t = p[x].pre;
    p[x].pre = find(t);
    p[x].re = (p[x].re + p[t].re) % 2;
    return p[x].pre;
}

int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--){
        int ans = 0,n,m;
        
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;++i){
            p[i].pre = i;
            p[i].re = 0;
        }
        
        char arr[20];
        int a,b,op;
        for(int i = 1;i <= m;++i){
            
            scanf("%d %d %s",&a,&b,arr);
            if(a > n || b > n){ans++; continue;}
            
            if(arr[0] == 'n')   op = 1;
            else    op = 0;

            if(op == 1 && a == b){ans++; continue;}

            int root1 = find(a);
            int root2 = find(b);
            if(root1 != root2){
                p[root2].pre = root1;
                p[root2].re = (2 + op + p[a].re - p[b].re) % 2;
            }
            else
                if((2 - p[a].re + p[b].re) % 2 != op){ans++;  continue;}

        }
        if(ans > 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
       
}


