#include <bits/stdc++.h>

using namespace std;

int a[10000],n,m;

int check(int mid)
{
    int i,sum = 0,now = 1;
    for(i = 0;i < n;++i)
    {
        if(a[i] - now >= mid)
        {
            sum++;
            now = a[i];
        }
    }
    if(sum + 1 >= m)
        return 1;
    else
        return 0;
}
    
int main()
{   
    int i,maxa;
    cin >> n >> m;
    for(i = 0;i < n;++i)
    {
        cin >> a[i];
        maxa = max(maxa,a[i]);
    }

    sort(a,a + n);

    int l = 0,r = maxa,mid;

    while(l < r)
    {
        mid = (l + r + 1) >> 1;
        if(check(mid))
            l = mid;
        else 
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
