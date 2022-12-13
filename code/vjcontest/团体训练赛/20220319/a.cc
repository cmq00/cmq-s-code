#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[20];
int vis[20];
int sum;
//int ans[100005];

void solve()
{
    memset(vis,0,sizeof(vis));
    //memset(sum,0,sizeof(sum));
    int maxx = -1;
    for(int i = 0;i <= 9;++i){
        cin >> a[i];
        sum += a[i];
        maxx = max(a[i],maxx);
    }
    if((maxx = a[0] && maxx > sum - maxx) || (maxx != a[0] && (maxx > sum - maxx + 1 ))){
        cout << "-1" << endl;
        return ;
    }
    vector<int> v;
    vis[0] = 1;
    for(int i = 1;i <= 9;++i){
        while(a[i] > 0){
           if(!v.empty() && i == v[v.size() - 1])
                    break;
            //printf("i:%d\n",i);
            v.push_back(i);
            a[i]--;
            for(int j = 0;j <= 9;++j){ 
                if(a[j]){
                    v.push_back(j);
                    a[j]--;
                    break;
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0;i <= 9;++i)
        if(a[i])
            cnt = a[i];
    printf("cnt:%d\n",cnt);
            
    for(int i = 0;i < v.size();++i){
        cout << v[i];
        //if(v[i + 2] == num)
            //cout << num;
    }
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}