#include <bits/stdc++.h>

using namespace std;

int a[10000],n,m;

int check(int mid)
{
    int i,sum = 0,cont = 0;
    for(i = 1;i <= n;++i)
    {
        
        if(sum + a[i] <= mid)
            sum += a[i];
        else
            sum = a[i],cont++;
    }
    if(cont >= m)
        return 1;
    else
        return 0;
}

int main()
{
    int i,sum = 0,maxa = 0;
    cin >> n >> m;

    for(i = 1;i <= n;++i)
    {
        cin >> a[i];
        sum += a[i];
        maxa = max(a[i],maxa);
    }

    int l = maxa,r = sum,mid;
    printf("%d %d\n",l,r);

    while(l <= r)
    {   
        mid = (l + r) >> 1;
        cout << l <<" "<< r <<" "<< mid << endl;
        if(check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l<< endl;
    return 0;
}
            

    



    
