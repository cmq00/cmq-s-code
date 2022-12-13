#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 10;
int a[N],ans[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]);
       
    stack<int> s;
    for(int i = n;i >= 1;--i){
        while(!s.empty() && a[s.top()] <= a[i]){
            s.pop();
        }
        if(s.empty())
            ans[i] = 0;
        else
            ans[i] = s.top();
        s.push(i);
        }
    for(int i = 1;i <= n;++i)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}