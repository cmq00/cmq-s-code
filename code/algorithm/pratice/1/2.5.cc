#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,i;
    while(~scanf("%d %d",&n,&m)){
        if(n == 0 && m == 0)
            break;
        int flag[310] = {0};
        int index = -1;
        int count = 0;
        for(i = 1;i < n;++i){
            count = 0;
            while(count != m){
                index = (index + 1) % n;
                if(flag[index] == 0){
                    count++;
                    if(count == m){
                        flag[index] = 1;
                    }
                }
            }
        }
        for(int j = 0;j < n;++j){
            //printf("%d ",flag[j]);
            if(flag[j] == 0){
                printf("%d\n",j + 1);
                break;
            }
        }
    }
    return 0;
}
            
