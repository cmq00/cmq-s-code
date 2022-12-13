#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string word;
    while(~scanf("%d",&t)){
    map<char,char> mp;
    int flag1 = 0,flag2 = 0;
    while(t--){
        cin >> word;
        if(word[0] == 's')
            flag1 = 1;
        if(word[word.length() - 1] == 'w')
            flag2 = 1;
        mp[word[0]] = word[word.length() - 1];
    }
    if(!flag1 || !flag2){
        printf("No\n");
        return 0;
    }
    char ch = 's';
    flag1 = 0;
    bool vis[1000];
    while((mp[ch] >= 'a' && mp[ch] <= 'z') || (mp[ch] >= 'A' && mp[ch] <= 'Z')){
        if(mp[ch] == 'w'){flag1 = 1;break;}
        if(vis[ch])
            break;
        vis[ch] = 1;
        ch = mp[ch];
    }
    if(flag1 == 1)
        printf("Yes\n");
    else   
        printf("No\n");
    }
    return 0;
}