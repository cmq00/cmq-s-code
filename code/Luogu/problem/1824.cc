#include <bits/stdc++.h>

using namespace std;

int a[100004],n,m;

int check(int mid)
{
    int i,j = 1,cont = 0;
    
    for(i = 1;i <= n;++i)
    {
        if(a[i] - a[j] >= mid)
            cont++,j = i;
    }
    if(cont + 1 >= m)
        return 1;
    else
        return 0;
}

int main()
{
    int maxa = 0,i;
    cin >> n >> m;

    for(i = 1;i <= n;++i)
    {    
        cin >> a[i];
        maxa = max(maxa,a[i]);
    }

    sort(a + 1,a + n + 1);
    for(i = 1;i <= n;++i)
        cout << a[i] << " ";
    cout << endl;


    int l = 0,r = maxa,mid;

    while(l < r)
    {
        mid = (r + l + 1) >> 1;
        cout <<"l:"<< l<< " r:"<<r<<" mid:"<<mid<<endl;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}

