#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        set<int> s;
        int n,m;
        scanf("%d %d",&n,&m);
        while(n--){
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        while(m--){
            int x0,y0,x1,y1;
            scanf("%d %d %d %d",x0,&y0,&x1,&y1);
            set<int>::iterator it;
            it= s.lower_bound(y0);
        }
    }

}