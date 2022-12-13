#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;

int main()
{
    int t;
    long long a[N],sum,flag;
    scanf("%d",&t);
    while(t--){
        unordered_map<int,int> mp;
        mp[0] = 1;
        int n,s;
        flag = sum = 0;
        scanf("%d %d",&n,&s);
        for(int k = 1;k <= n;++k){
            scanf("%d",&a[k]);
            sum = sum + a[k];
            //cout << "flag: " << flag << endl;
            //cout << sum[k] << " ";
            if(mp.find(sum - s) != mp.end())
                flag = 1;
            mp[sum]++;
        }
        //cout << endl;
        //for(int i = 1;i <= n;++i)
            //printf("%d ",sum[i]);
        //cout << endl;
        if(flag == 1)
            printf("YES\n");
        else    
            printf("NO\n");
    }
    return 0;
}