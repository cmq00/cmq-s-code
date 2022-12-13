#include <bits/stdc++.h>

using namespace std;
int cnt[5],ans = 0;
int fun(char ch)
{
    if('a'<=ch&&ch<='z')
        return 1;
    else if('A'<=ch&&ch<='Z')
        return 2;
    else if('0'<=ch&&ch<='9')
        return 3;
    else
        return 4;
}

bool cheak()
{
    int a=0;
    for(int i=1;i<=4;++i){
        if(cnt[i]!=0)
            a++;
    }
    if(a>=3)
        return 1;
    else
        return 0;
}

int main()
{
    int n,L,R;
    cin>>n>>L>>R;
    char a[100004];
    for(int i = 1;i<=n;++i)
        cin>>a[i];
     /* for(int i = 1;i<=n;++i)
        cout<<a[i];
    cout <<endl;*/
    for(int i=1;i<=n-R;++i){
        for(int l = i;l<=i+L-1;++l){
            cnt[fun(a[l])]++;
        }
        if(cheak())
            ans++;
        for(int j = i+L;j<=i+R-1;++j){
            cnt[fun(a[j])]++;
        }
        if(cheak())
            ans++;
        for(int l = i;l<=i+R-L;++l)
            cnt[fun(a[l])]--;
        if(cheak())
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}