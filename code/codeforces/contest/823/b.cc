#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
double topos;
int n;

struct Node
{
    double pos;
    ll t;
}a[N];

bool cmp1(Node x,Node y)
{
    return x.pos < y.pos;
}

bool cmp2(Node x,Node y)
{
    return x.t < y.t;
}

bool check(double mid)
{
     for(int i = 2;i <= n;++i){
            if(a[i].pos < topos){
                if(a[i].t +  topos- a[i].pos > mid){
                    cout << a[i].t +  topos- a[i].pos << endl;
                    return -1;
                }
            }
            else{
                if(a[i].t + a[i].pos - topos > mid)
                    return -1;
            }
        }
        return 1;
}



void solve()
{
    cin >> n;
    double p = 0;
    for(int i = 1;i <= n;++i){
        cin >> a[i].pos;
        p = max(p,a[i].pos);
    }
    for(int i = 1;i <= n;++i){
        cin >> a[i].t;
    }
    sort(a + 1,a + 1 + n,cmp2);
    double l,r,mid;
    l = a[1].t,r = a[n].t + p - a[1].pos + a[1].t;
    sort(a + 1,a + 1 + n,cmp1);
    while(r - l > 1e-6){
        mid = (l + r) / 2;
         topos = a[1].pos + mid - a[1].t;
        cout << "l:" << l << " r:" << r << " mid:" << mid << " topos: " << topos << endl;
        if(check(mid))
            l = mid;
        else
            r = mid;  
    }
    cout << l << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}