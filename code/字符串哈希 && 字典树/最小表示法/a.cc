#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
char a[N * 2 + 4];
int n;

int getmin()
{
    int i = 0,j = 1,k = 0;
    while(i < n && j < n && k < n){
       int t = a[i + k] - a[j + k];
       if(!t)
            k++;
        else{
            if(t > 0)   
                i += k + 1;
            else
                j += k + 1;
            if(i == j)
                j += 1;
            k = 0; 
        }
    }
    return min(i,j);
}

int main()
{
    scanf("%d",&n);
    char ch = getchar();
    scanf("%s",a);
    for(int i = 0;i < n;++i)
        a[n + i] = a[i];
    /*for(int i = 0;i < 2 * n;++i)
        cout << a[i];
    cout << endl;*/
    //cout << getmin() << endl;
    for(int i = getmin();i < getmin() + n;++i)
        cout << a[i];
    cout << endl;
    return 0;
}