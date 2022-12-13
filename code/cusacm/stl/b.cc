#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n){
        set<int> s;
        for(int i = 1;i <= n * n;++i){
            int x;
            cin >> x;
            s.insert(x);
        }
        set<int>::iterator it;
        int i;
        for(it = s.begin(),i = 1;it != s.begin() && i <= n;++it){
            printf("%d ",*it);
        }
        printf("\n");
    }
}