#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
bool vis[N];
ll aa[N],bb[N];

void solve()
{
    vector<ll> a;
    vector<ll> b;
    vector<ll> ans;
    map<int,int> mp;
    map<int,int> mpa;
    map<int,int> mpb;
    int n,k;
    ll cnt = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;++i){
        cin >> aa[i];
        a.push_back(aa[i]);
    } 
    sort(a.begin(),a.end());
    for(ll i = 1;i <= n;++i){
        //vector<ll>::iterator pos = find(a.begin(),a.end(),aa[i]); 
        int pos = find(a.begin(),a.end(),aa[i]) - a.begin(); 
        mpa[pos] = i;
    }
    for(int i = 1;i <= n;++i){
        cin >> bb[i];
        b.push_back(bb[i]);
    }   
    sort(b.begin(),b.end());
    for(ll i = 1;i <= n;++i){
        //vector<ll>::iterator pos = find(a.begin(),a.end(),aa[i]); 
        int pos = find(b.begin(),b.end(),bb[i]) - b.begin(); 
        mp[mpb[pos]] = i;
    }
   
    for(int i = 0;i < b.size();++i){
        int pos = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
        if(pos != a.size()){
            mp[mpb[i]] = pos;
            ans.push_back(mp[pos]);
            vis[pos] = 1;
        }
    }

    int pos = 0;
    for(int i = 0;i < a.size();++i){
        if(!vis[i]){
            pos = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
            if(pos != b.size()){
                mp[mpb[i]] = pos;
                ans.push_back(mp[i]);
                cnt += b[pos] - a[i];
            }
            break;
        }
    }
    cout << "pos: " << pos << endl;
    for(int i = pos + 1;i < a.size();++i){
        cnt += b[i] - a[i];
        mp[mpb[i]] = mpa[i];
        ans.push_back(mp[i]);
    }
    cout << cnt / k << endl;
    for(int i = 0;i < ans.size();++i){
        cout << mp[i] << " ";
    }
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}
