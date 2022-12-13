#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e6 + 7;

set<int> s[N];
int ans[N];

struct ddd
{
    int id;
    bool operator>(const ddd &b) const
    {
        return s[id].size() <= s[b.id].size();
    }
};

priority_queue<ddd, vector<ddd>, greater<ddd> > q;

int n;

void fini()
{
    run(i, 1, n) s[i].clear(), ans[i] = 0;
    while(!q.empty()) q.pop();
}

void solve()
{
    cin >> n;
    run(i, 1, n)
    {
        int f;
        cin >> f;
        s[f].insert(i);
    }
    run(i, 1, n)
    {
        ddd o;
        o.id = i;
        q.push(o);
    }
    while(!q.empty())
    {
        ddd a = q.top();
        if(!s[a.id].size())
            break;
        q.pop();
        if(q.empty())
        {
            bool f = 0;
            run(i, 1, n)
            if(!ans[i])
            {
                auto it = s[a.id].lower_bound(i);
                if(it == s[a.id].end())
                {
                    ans[i] = a.id;
                    f = 1;
                    break;
                }
            }
            if(f)
                break;
            cout << "NO" << '\n';
            fini();
            return;
        }
        ddd b = q.top();
        if(s[b.id].size())
        {
            int p = *s[b.id].begin();
            ans[p] = a.id;
            s[b.id].erase(p);
        }
        else
        {
            bool f = 0;
            run(i, 1, n)
            if(!ans[i])
            {
                auto it = s[a.id].lower_bound(i);
                if(it == s[a.id].end())
                {
                    ans[i] = a.id;
                    f = 1;
                    break;
                }
            }
            if(f)
                break;
            cout << "NO" << '\n';
            fini();
            return;
        }
    }
    int st = 1;
    while(!q.empty())
    {
        ddd a = q.top();
        q.pop();
        run(i, st, n)
            if(!ans[i])
            {
                ans[i] = a.id;
                st = i;
                break;
            }
    }
    cout << "YES" << '\n';
    run(i, 1, n)
        cout << ans[i] << " \n"[i == n];
    fini();
}

int main()
{
    speed
    t()
    solve();
    return 0;
}