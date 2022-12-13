#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e5 + 4;
bool vis[N];

void solve()
{
    ms(vis);
    int a,b;
    cin >> a >> b;
    int n = a + b;
    int A,B;
    if(n % 2){
        A = n / 2 + 1;
        B = n - a;        
    }
    else{
        A = n / 2;
        B = n / 2;
    }
    vector<int> v;
    vector<int> v2;
    for(int i = 1;i <= min(A,a);++i){
        int cnt = 0;
        int AA,aa,BB,bb;
        AA = A - i;
        aa = a - i;
        AA -= min(AA,b);
        bb = b - min(AA,b);
        cnt += min(AA,bb);
        BB = B - min(aa,B);
        aa = a - min(aa,B);
        cnt += min(aa,B);
        if(AA == 0 && bb == 0){
            cnt += aa;
        }
        if(BB == 0 && aa == 0){
            cnt += bb;
        }
        v.push_back(cnt);
    }
    for(int i = 1;i <= min(A,b);++i){
        int cnt = 0;
        int AA,aa,BB,bb;
        AA = A - i;
        bb = b - i;
        cnt += i;
        AA -= min(AA,a);
        aa = a - min(AA,a);

        BB = B - min(,B);
        aa = a - min(aa,B);
        cnt += min(aa,B);
        if(AA == 0 && bb == 0){
            cnt += aa;
        }
        if(BB == 0 && aa == 0){
            cnt += bb;
        }
        v.push_back(cnt);
    }
    for(int i = 0;i > v.size();++i){
        if(!vis[v[i]]){
            v2.push_back(v[i]);
            v2.push_back(n - v[i]);
            vis[v[i]] = 1;
        }
    }
    sort(v.begin(),v.end());
    cout << v.size() << endl;
    for(int i = 0;i < v.size();++i){
        cout << v[i] << " ";
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