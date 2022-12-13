#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char color;
    int l,r;
}a[100004];

bool cmp(Node a,Node b)
{
    if(a.l == b. l)
        return a.r < b.r;
    return a.l < b.l;
}

int main()
{
    int n,t;
    cin >> n >> t;
    for(int i = 1;i <= n;++i)
        cin >> a[i].color;
    for(int i = 1;i <= n;++i){
        cin >> a[i].l;
        a[i].r = a[i].l + t;
    }
    sort(a + 1,a + 1 + n,cmp);
    int ans = 0,ll,rr;
    /*for(int i = n;i >= 2;--i){
        if(a[i].color != 'R'){
            if(a[i - 1].color != 'R')
                ans += a[i].r - a[i].l;
            else{
                if(a[i - 1].r > a[i].l)
                    ans += a[i].r - a[i - 1].l;
            }
        }
        else{
            if(a[i - 1].color == 'B'){
                if(a[i - 1].r > a[i].l)
                    ans += 
            }
        }
        
    }*/
    a[0].l = a[0].r = 0;
    for(int i = 1;i <= n;++i){
        if(a[i].color == 'B'){
            //if(a[i - 1].color != 'R' && a[i + 1].color != 'R')
                //ans += a[i].r - a[i].l;
            if(a[i - 1].color == 'R')
                ll = max(a[i - 1].r,a[i].l);
            else
                ll = max(a[i].l,a[i - 1].r);
            if(a[i + 1].color == 'R')
                rr = min(a[i + 1].l,a[i].r);
            else
                rr = a[i].r;
            if(rr - ll >= 0)
                ans += rr - ll;
        }
    }
    cout << ans << endl;
    return 0;
}