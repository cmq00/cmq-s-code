#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    int n,m,rb,cb,rd,cd;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d %d",&n,&m,&rb,&cb,&rd,&cd);
        int dr = 1,dc = 1;
        int time = 0,timex,timey;
       /* while(rd != rb && cd != cb){
            //if(rd == rb || cd == cb)
                //break;
            rb += dr;
            cb += dc;
            time++;
            if(cb == 1 || cb == m)
                dc = -dc;
            if(rb == 1 || rb == n)
                dr = -dr;
        }*/
        if(rb <= rd)
            timex = rd - rb;
        else
            timex = 2 * n - rb - rd;
        if(cb <= cd)
            timey = cd - cb;
        else
            timey = 2 * m - cd - cb;    
        
        time = min(timex,timey);
        printf("%d\n",time);
    }
    return 0;
}