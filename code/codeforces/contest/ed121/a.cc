#include <bits/stdc++.h>

using namespace std;

bool cmp(char a,char b)
{
    return a < b;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int cnt = 0;
        char a[100];
        //int vis[100];
        //memset(vis,0,sizeof(vis));
        scanf("%s",a);
        int len = strlen(a);
        /*for(int i = 0;a[i] != '\0';++i){
            int c = a[i] - 'a';
            if(!vis[c])
                vis[c] = 1;
            if(vis[c]){
                vis[c] = 2;
                cnt++;
            }
        }*/
       sort(a,a + len,cmp);
       printf("%s\n",a);
    }
    return 0;

}