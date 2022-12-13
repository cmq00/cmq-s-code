#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long 
ll t, n, m;
struct per
{
	map<string,int>mark;
	vector<string>s;
};
map<string, per>tag;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (tag[s1].mark[s2]&&tag[s1].s.size()<5) {
			int tot = 1;
			for (int i = tag[s1].mark[s2]; i < tag[s1].s.size(); i++) {
				tag[s1].mark[tag[s1].s[i]] = tot++;
			}
			tag[s1].s.erase(tag[s1].s.begin(), tag[s1].s.begin() + tag[s1].mark[s2] );
		}
		tag[s1].s.push_back(s2);
		tag[s1].mark[s2] = (int)tag[s1].s.size();
	}
	for (auto it = tag.begin(); it != tag.end(); it++) {
		if (tag[it->first].s.size() >= 5) {
			cout << "PENTA KILL!" << endl;
			return 0;
		}
	}
	cout << "SAD:(" << endl;
	return 0;
}