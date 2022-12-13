#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 4;

int trie[N][26];//字典树
int fail[N];
int cntword[N];
int vis[N];
int cnt,ans;
string s;

void putin(string s)
{
    int root = 0;
    for(int i = 0;i < s.size();++i){
        int next = s[i] - 'a';
        if(!trie[root][next])
            trie[root][next] = ++cnt;
        root = trie[root][next];
    }
    cntword[root]++;
} 

void getfail()
{
    queue<int> q;
    for(int i = 1;i < 26;++i){
        if(trie[0][i]){
            q.push(trie[0][i]);
            fail[trie[0][i]] = 0;
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 1;i < 26;++i){
            if(trie[now][i]){
                fail[trie[now][i]] = trie[fail[now]][i];
                q.push(trie[now][i]);
            }
        else
            trie[now][i] = trie[fail[now]][i];
        }    
    }
}

int query(string s)
{
    int now = 0,len = s.size();
    for(int i = 0;i < len;++i){
        int x = trie[now][s[i] - 'a'];
        vis[now] = 1;
        while(x && !vis[x]){
            ans += cntword[x];
            vis[x] = 1;
            x = fail[x];
        }
        now = trie[now][s[i] - 'a'];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> s;
        putin(s);
    }
    getfail();
    fail[0] = 0;
    cin >> s;
    cout << query(s) << endl;
    return 0;
}