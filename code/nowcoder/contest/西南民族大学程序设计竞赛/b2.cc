#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for(int (i) = (l); (i) <= (r); ++(i))
#define ull unsigned long long

const int maxn = 1e5+10;
const int inf = 123456789;
int t,i,j; 
int n,m;
ll u,v,w;
ll dis[maxn];
bool vis[maxn];
struct node{
	ll v,w;
	bool operator < (const node &a) const {
		return a.w<w;
	}
};

vector<node> mp[maxn];
priority_queue<node> q;

void dijk(){
	dis[1] = 0;
	q.push((node){1,0});
	while(!q.empty()){
		node tmp = q.top();
		q.pop();
		int x = tmp.v;
		//cout<<x<<endl;
		if(vis[x]) continue;
		
		vis[x] = 1;
		//cout<<x<<endl;
		int len = mp[x].size();
		//cout<<len;
		for(int i=0;i<len;i++){
			int to = mp[x][i].v;
			//cout<<to<<endl;
			//cout<<dis[to]<<" "<< mp[x][i].w + dis[x]<<endl;
			if(dis[to] > mp[x][i].w + dis[x]){
				dis[to] = mp[x][i].w + dis[x];
				if(!vis[to]){
					//cout<<to<<endl;
					q.push((node){to,dis[to]});
				}
			}
		}
	}
}



int main(){
	memset(dis,inf,sizeof(dis));
		cin>>n>>m;
		rep(i,1,m){
			cin>>u>>v>>w;
			mp[u].push_back((node){v,w});
            mp[v].push_back((node){u,w});
		}
		dijk();
        int tmp,q;
        cin>>q;
		rep(i,1,q){
            cin>>tmp;
			cout<<dis[tmp]<<"\n";
		}
    return 0; 
}