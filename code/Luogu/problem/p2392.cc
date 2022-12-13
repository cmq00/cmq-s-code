#include <bits/stdc++.h>
#define ll long long

using namespace std;

int s1,s2,s3,s4,ans;
int a[100],b[100],c[100],d[100];

int fun(int arr[],int len)
{
    int sum = arr[len];
    int t = 0;
    int res = arr[len];
    for(int i = len - 1;i >= 1;--i){
        if(t + arr[i] <= sum){
            t += arr[i];
        }
        else{
            arr[i] = t + arr[i] - sum;
            t = 0;
            sum = arr[i];
            res += sum;
        }
    }
    return res;
}
int main()
{
    cin >> s1 >> s2 >> s3 >> s4;
    int ans = 0; 
    for(int i = 1;i <= s1;++i){
       cin >> a[i]; 
    }
    for(int i = 1;i <= s2;++i){
        cin >> b[i];
    }
    for(int i = 1;i <= s3;++i){
        cin >> c[i];
    }
    for(int i = 1;i <= s4;++i){
        cin >> d[i];
    }
    sort(a + 1,a + 1 + s1);
    sort(b + 1,b + 1 + s2);
    sort(c + 1,c + 1 + s3);
    sort(d + 1,d + 1 + s4);
    ans += fun(a,s1)  + fun(b,s2) + fun(c,s3) + fun(d,s4); 
    cout << ans << endl;    
    return 0;
}

