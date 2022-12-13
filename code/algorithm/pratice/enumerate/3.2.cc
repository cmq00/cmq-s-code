#include <bits/stdc++.h>

using namespace std;

int status[12];
char Left[3][7],Right[3][7],result[3][7];

bool balance()
{
    int l,r,i,k;
    for(i = 0;i < 3;++i){
        l = r = 0;
        for(k = 0;Left[i][k] != '\0';k++){
            l += status[Left[i][k] - 'A'];
            r += status[Right[i][k] - 'A'];
        }
        if(l > r && result[i][0] != 'u')
            return 0;
        if(l == r && result[i][0] != 'e')
            return 0;
        if(l < r && result[i][0] != 'd')
            return 0;
        }
    return 1;
}

int main()
{
    int i,t;
    scanf("%d",&t);
    while(t--){
        for(i = 0;i < 3;++i)
            scanf("%s %s %s",Left[i],Right[i],result[i]);
        for(i = 0;i < 12;++i)
            status[i] = 0;
        for(i = 0;i < 12;++i){
            status[i] = 1;
            if(balance())
                break;
            status[i] = -1;
            if(balance())
                break;
            status[i] = 0;
        }
        //printf("%d\n",i);
        printf("%c is the counterfeit coin and it is %s.\n",i + 'A',(status[i] > 0) ? "heavy":"light");
    }
    return 0;
}


        

