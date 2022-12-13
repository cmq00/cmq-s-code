#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;

ll sum[N];

struct Node
{
    int h,w;
}a[N];

bool cmp(Node x,Node y)
{
    if(x.h == y.h)
        return x.w < y.h;
    return x.w < y.w; 
}

void solve()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;++i){
        cin >> a[i].h >> a[i].w;
    }
    sort(a + 1,a + 1 + n,cmp);
    for(int i = 1;i <= n;++i){
        sum[i] = sum[i - 1] + a[i].h * a[i].w;
    }
    while(q--){
        ll res = 0;
        int hs,ws,hb,wb;
        cin >> hs >> ws >> hb >> wb;
        int posh = 0,posw = 0;
        int l = 0,r = n,mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(a[mid].h < hb) r = mid;
            else
                l = mid + 1;
        }
        posh = l;
        l = 0,r = n;
        while(l < r){
            mid = (l + r) >> 1;
            if(a[mid].w < wb)
                r = mid;
            else
                l = mid + 1;
        }
        posw = l;
        int pos = max(posh,posw);
        res += sum[n] - sum[pos - 1];
        cout << res << endl;
    }

}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}