#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[100004];
    //string s;
    int n;
    cin >> n;
   //cout << n;
    for(int i = 1;i <= n;++i)
        cin >> s[i];
    //cout << s;
    int flag = -1,pos = 0;
    for(int i = 1;i <= n;++i){
        if(flag == 1 && s[i] == '0')
            {swap(s[pos],s[i]);break;}
        if(flag == 0 && s[i] == '1')
            {swap(s[pos],s[i]);break;}
        if(s[i] == '1')
            flag = 1,pos = i;
        if(s[i] == '0')
            flag = 0,pos = i;
    }
    for(int i = 1;i <= n;++i)
        cout << s[i];
    cout << endl;
    return 0;
}