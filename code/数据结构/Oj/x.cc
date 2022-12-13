#include <bits/stdc++.h>

using namespace std;

int a[1004];

void BubbleSort(int a[],int n)
{
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n - i;++j){
            if(a[j] < a[j + 1])
                swap(a[j],a[j + 1]);
        }
    }
}

int main()
{
    int n = 3;
    while(n--){
        if(n != 2)
            puts("");
        int t = 1;
        int x;
        while(cin >> x){
            a[t++] = x;
            if(getchar() == '\n')
                break; 
        }
        t--;
        BubbleSort(a,t);
        cout << a[1];
        for(int i = 2;i <= t;++i)
            cout << " " << a[i];
        memset(a,0,t);
    }
}