#include <bits/stdc++.h>

using namespace std;

int a[1004];

int Partition(int a[],int l,int r)
{
    a[0] = a[l];
    int p = a[l];
    while(l < r){
        while(l < r && a[r] >= p)
            --r;
        a[l] = a[r];
        while(l < r && a[l] <= p)
            ++l;
        a[r] = a[l];
    }
    a[l] = a[0];
    return l;
}


void QSort(int a[],int l,int r)
{
    Partition(a,l,r);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    QSort(a,1,n);
    cout << a[1];
    for(int i = 2;i <= n;++i){
        cout << " " << a[i];
    }
    return 0;
}