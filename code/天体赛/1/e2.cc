#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    char ch;
    vector<char> v;
    while(cin >> ch && ch != '\n'){
        if(ch != '6' && v.empty())
            cout << ch;
        if(ch != '6' && !v.empty()){
            int len = v.size();
            if(len <= 6){
                for(int i = 0;i < v.size();++i)
                    cout << v[i];
            }
            if(len > 6)
                cout << "9";
            if(len > 9)
                cout << "27";
            cout << ch;
            vector<int> v;
        }
        else{
            v.push_back(ch);
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}