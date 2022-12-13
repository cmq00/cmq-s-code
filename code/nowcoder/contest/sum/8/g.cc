//https://ac.nowcoder.com/acm/contest/33194/G
#include<bits/stdc++.h>
#define IOS	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define ll long long
#define INF 0x3f3f3f
const ll N = 1e6 + 10;
using namespace std;
//素数判断 primejudge
//高精度 + - * /
//质因数分解 pf
ll p[600010],T,ans;
string s;
unordered_map<string, ll>markans;
unordered_map<string, bool>flag;
ll  solve()
{
	for (ll j = 1; j <= T; j++) {

		if (j == 1) {
			string t;
			cin >> s;
			t += "$#";
			for (ll i = 0; i < s.size(); i++) {
				t += s[i];
				t += "#";
			}
			ll mx = 0, mid = 0;
			for (ll i = 1; i < t.size(); i++) {
				p[i] = i < mx ? min(p[2 * mid - i], mx - i) : 1;
				while (t[i - p[i]] == t[i + p[i]]) { 
					p[i]++;
					string tmp = s.substr((i - p[i]) >> 1, p[i] - 1);
					string tmp1 =tmp ;
					reverse(tmp.begin(), tmp.end());
					if (tmp == tmp1) { markans[tmp1] = 1; } 
				}
				if (p[i] + i > mx) {
					mx = p[i] + i;
					mid = i;
				}
			}
		}
		else {
			string t;
			cin >> s;
			t += "$#";
			for (ll i = 0; i < s.size(); i++) {
				t += s[i];
				t += "#";
			}
			ll mx = 0, mid = 0;
			for (ll i = 1; i < t.size(); i++) {
				p[i] = i < mx ? min(p[2 * mid - i], mx - i) : 1;
				while (t[i - p[i]] == t[i + p[i]]) { 
					p[i]++;
					string tmp = s.substr((i - p[i]) >> 1, p[i] - 1);
					string tmp1 = tmp;
					reverse(tmp.begin(), tmp.end());
					if (!flag[tmp]&&tmp==tmp1) {
						markans[tmp]++;
						flag[tmp1] = 1;
					}
				}
				if (p[i] + i > mx) {
					mx = p[i] + i;
					mid = i;
				}
			}
			{
				unordered_map<string, bool>tmp;
				flag.swap(tmp);
			}
		}

	}
	for (auto it = markans.begin(); it != markans.end(); it++) { if (it->second == T) { ans++; } } 
	return ans;
}
int main()
{
	IOS;
	cin >> T;
	cout<<solve();
	return 0;
}
