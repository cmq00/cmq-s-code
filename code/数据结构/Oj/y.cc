#include <bits/stdc++.h>

using namespace std;

int a[1004];

void SelectSort(int a[],int n)
{
    int pos;
    for(int i = 1;i <= n;++i){
        int maxx = 0x3f3f3f;
        for(int j = i;j <= n;++j){
            if(a[j] < maxx){
                pos = j;
                maxx = a[j];
            }
        }
        if(i != pos)
            swap(a[i],a[pos]);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    SelectSort(a,n);
    cout << a[1];
    for(int i = 2;i <= n;++i)
        cout << " " << a[i];
}