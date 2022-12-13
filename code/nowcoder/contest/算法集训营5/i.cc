#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
int n,q,k,p,pos;
int a[N + 4],vis[N + 4],ans[N + 4];

int main()
{   
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= n - 1;++i)
        vis[i] = a[i + 1] - a[i];
    sort(vis + 1,vis + n);
    /*for(int i = 1;i <= n - 1;++i)
        cout << vis[i] << " ";
    cout << endl;*/
    for(int i = 1;i <= N;++i){
        //cout << "i:" << i << endl;
        if(i >= vis[n - 1])
            break;
        for(int j = lower_bound(vis + 1,vis + n,i) - vis;j <= n - 1;++j){
            //cout << "j:" << j << endl;
            if(vis[j] <= i)
                continue;
            if(vis[j] > i){
                ans[i] += vis[j] - i;
                //if(!pos)
                    //pos = j;
            }
        }
    }
    /*for(int i = 1;i <= 10;++i)
        cout << ans[i] << " ";
    cout << endl;*/
    while(q--){
        cin >> k >> p;
        if(ans[k] >= p)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}