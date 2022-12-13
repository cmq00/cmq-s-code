#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
const int N = 1e5 + 4;

struct Node
{
    int pos;
};

void solve()
{
    vector <int> v[N];
    int a[N],maxx = 0,j = 1;
    cin >> n;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    maxx = a[1];
    v[j].push_back(maxx);
    for(int i = 2;i <= n;++i){
        if(a[i] < maxx){
            v[j].push_back(i);
        }
        else{
            maxx = a[i]; 
            j++;
            v[j].push_back(maxx);
        }
    }
    //j -= 1;
    //printf("j :%d\n",j);
    int cnt = 0;
    for(int i = 2;i <= j;++i){
        for(int k = 1;k < v[i].size();++k){
            if(a[v[i][k]] < v[i - 1][0]){
                cnt++;
                break;
            }
        }
    }
    cout << j - cnt << endl;
    
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}