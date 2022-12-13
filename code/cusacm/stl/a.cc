#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    int count = 1;
    while(cin >> n >> m){
        vector<int> v;
        if(n == 0 && m == 0)
            break;
        
        while(n--){
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        printf("CASE# %d:\n",count++);
        while(m--){
            int a;
            scanf("%d",&a);
            vector<int>::iterator it;
            it = find(v.begin(),v.end(),a);
            int pos = find(v.begin(),v.end(),a) - v.begin();
            if(it != v.end())
                printf("%d found at %d\n",a,pos + 1);
            else   
                printf("%d not found\n",a);
        }

    }
    return 0;
}