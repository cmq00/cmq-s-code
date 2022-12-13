#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>

using namespace std;

const int N = 1e3+10;
map<int, bool> mp;
int ans = 0;
int a[5];
int x, y, z, w,xx,yy;
bool vis[5];

void check(int t)
{
    if(t >= 0 && !mp[t])
    {
        ans++;
        mp[t] = 1;
    }
}
void fun2(int x, int y)
{
    int t;
    t = x + y;
    check(t);
    t = x * y;
    check(t);
    t = x - y;
    check(t);
}
void fun3(int x, int y, int z)
{
    int t;
    t = x + y + z;
    check(t);
    t = x + y * z;
    check(t);
    t = x + y - z;
    check(t);
    t = x - y + z;
    check(t);
    t = x - y * z;
    check(t);
    t = x - y - z;
    check(t);
    t = x * y + z;
    check(t);
    t = x * y * z;
    check(t);
    t = x * y - z;
    check(t);

}
void fun4(int x,int y,int z,int w)
{
    int t;
    t = x + y + z + w;
    check(t);
    t = x + y + z - w;
    check(t);
    t = x + y + z * w;
    check(t);
    t = x + y - z + w;
    check(t);
    t = x + y - z - w;
    check(t);
    t = x + y - z * w;
    check(t);
    t = x + y * z + w;
    check(t);
    t = x + y * z - w;
    check(t);
    t = x + y * z * w;
    check(t);

    t = x - y + z + w;
    check(t);
    t = x - y + z - w;
    check(t);
    t = x - y + z * w;
    check(t);
    t = x - y - z + w;
    check(t);
    t = x - y - z - w;
    check(t);
    t = x - y - z * w;
    check(t);
    t = x - y * z + w;
    check(t);
    t = x - y * z - w;
    check(t);
    t = x - y * z * w;
    check(t);

    t = x * y + z + w;
    check(t);
    t = x * y + z - w;
    check(t);
    t = x * y + z * w;
    check(t);
    t = x * y - z + w;
    check(t);
    t = x * y - z - w;
    check(t);
    t = x * y - z * w;
    check(t);
    t = x * y * z + w;
    check(t);
    t = x * y * z - w;
    check(t);
    t = x * y * z * w;
    check(t);
}
int main()
{
    run(i, 1, 4)
        scanf("%d", &a[i]);
    run(i, 1, 4)
    {
        vis[i] = 1;
        run(j, 1, 4)
        {
            if(vis[j])
                continue;
            vis[j] = 1;
            x = a[i] * 10 + a[j];
            run(k, 1, 4)
            {
                if(vis[k])
                    continue;
                vis[k] = 1;
                xx = a[i] * 100 + a[j] * 10 + a[k];
                run(l, 1, 4)
                {
                    if(vis[l])
                        continue;
                    y = a[k] * 10 + a[l];
                    yy = a[l];
//                    printf("%d  %d\n", x, y);
                    printf("%d  %d\n", xx, yy);
                    printf("%d  %d   %d\n", a[l], a[k], x);
                    printf("%d  %d   %d   %d\n", a[l], a[k], a[i], a[j]);
                    fun2(x, y);
                    fun2(xx, yy);
                    fun3(a[l],a[k],x);
                    fun3(a[l],x,a[k]);
                    fun3(a[k],x,a[l]);
                    fun3(a[l],a[k],x);
                    fun3(x,a[k],a[l]);
                    fun3(x,a[l],a[k]);
                    fun4(a[i],a[j],a[k],a[l]);
                }
                vis[k] = 0;
            }
            vis[j] = 0;
        }
        vis[i] = 0;
    }
      cout << ans << endl;
    return 0;
}