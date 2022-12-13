#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    char s1[1000004],s2[30];
    int vis[1000004];
    memset(vis,0,sizeof(vis));
    int l1,l2;
    cin >> l1 >> l2;
    for(int i = 1;i <= l1;++i){
        cin >> s1[i];
    }
    for(int i = 1;i <= l2;++i){
        cin >> s2[i];
    }
    int flag = 1,ans = 0;
    while(flag == 1){
        int p1 = 1,p2 = 1;
        while(p1 <= l1 && p2 <= l2){
            //printf("p1:%d p2:%d\n",p1,p2);
            if(!vis[p1]){
                if(s1[p1] == s2[p2])
                    vis[p1] = 1,p1++,p2++;
                else
                    p1++;
            }
            else
                p1++;
        }
        //printf("p1:%d p2:%d\n\n",p1,p2);
        if(p2 == l2 + 1)
            ans++;
        else
            flag = 0;
    }
    cout << ans << endl;
  
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}