#include  <bits/stdc++.h>

using namespace std;

int fa[500];

int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

int main()
{
    int t;
    while(cin >> t){
    for(int i = 1;i <= 499;++i)
        fa[i] = i;
    while(t--){
        string word;
        cin >> word;
        int xx = find(word[0]),yy = find(word[word.length() - 1]);
        if(xx != yy)
            fa[xx] = yy;
    }
    if(find('s') != find('w'))
        printf("No\n");
    else
        printf("Yes\n");
    }
    return 0;
}