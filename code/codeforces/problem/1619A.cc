#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int t;
    scanf("%d",&t);
    while(t--){
        cin >> s;
        int len = s.size();
        if(len % 2 != 0)
            printf("NO\n");
        else{
            int flag = 1;
            for(int i = 0,j = len / 2;i < len / 2;++i,++j){
                if(s[i] != s[j]){
                    flag = 0;
                    //printf("i:%d j:%d\n",i,j);
                }
            }
            if(flag == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}