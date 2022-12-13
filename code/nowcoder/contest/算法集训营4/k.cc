#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve(){
	int n;
	cin>>n;
	cout<<(1ll<<31)*n+n<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T=1;/*
	cin>>T;//*/
	while(T--) solve();
    cout << (1ll << 31) << endl;
	return 0;
}

