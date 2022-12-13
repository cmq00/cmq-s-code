#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[100004];
int ans[100004];
int pos[100004];
int vis[100004];

void solve()
{
    
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        vis[i] = 0;
    }
    set<int> s;
    vector<int> v;
    for(int i = 1;i <= n;++i){
        scanf("%d",&a[i]);
        if(!vis[a[i]]){
            pos[a[i]] = i;
            v.push_back(a[i]);
            vis[a[i]] = 1;
        }
        s.insert(a[i]);
    }
    // stack<int> st;
    // for(int i = 1;i <= n;++i){
    //     if(!vis[i]){
    //         st.push(i);
    //     }
    // }
    int cnt = 1;
    if(s.size() == 1){
        puts("NO");
        return ;
    }
    puts("YES");
    if(s.size() == n){
        cout << a[n] << " ";
        for(int i = 1;i <= n - 1;++i)
            printf("%d ",a[i]);
        printf("\n");
        return ;
    }
    int len = v.size();
    for(int i = 0;i < len - 1;++i){
        ans[pos[v[i + 1]]] = v[i];
    }
    ans[pos[v[0]]] = v[len - 1];
    int t = 1;
    for(int i = 1;i <= n;++i){
        while(t <= n && vis[t]) t++;
        if(!ans[i]){
            printf("%d ",t++);
        }
        else{
            printf("%d ",ans[i]);
        }
        ans[i] = 0;
    }
    puts("");
}

int main()//https://ac.nowcoder.com/acm/contest/33192/C
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    scanf("%d",&T);//*/
    while(T--) solve();
    return 0;
}