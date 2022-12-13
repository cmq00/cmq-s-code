#include <random>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll seed;
std::mt19937 rng(seed);
std::uniform_int_distribution<> u(1,400);

const int N = 2e6 + 4;
ll n,q;
int t[20];
const ll mod = 998244353;

struct Node
{
    int iq,eq,aq;
    //int maxx;
}a[20][N];

bool cmp(Node a,Node b)
{
    if(a.iq == b.iq){
        if(a.eq == b.eq){
            return a.aq < b.aq;
        }
        return a.eq < b.eq;
    }
    return a.iq < b.iq;
}

ll fpow(ll b, ll pow){
    long long result = 1;
    while (pow > 0){
        if (pow & 1)
            result = (result % mod  * b % mod) % mod;
        pow >>= 1;
        b = (b % mod * b % mod) % mod;
    }
    return result;
}

ll solve(ll iq,ll eq,ll aq)
{
    int cnt = 0;
    bool f = 1;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= t[i];j++){
                if(iq < a[i][j].iq || eq < a[i][j].eq || aq < a[i][j].aq)
                    break;
                else{
                    cnt++;
                    break;
                }
        }
    }
    return cnt;
}

int main()
{
    cin >> n  >> q;
    for(int i = 1;i <= n;++i){
        scanf("%d",&t[i]);
        for(int j = 1;j <= t[i];++j){
            scanf("%d %d %d",&a[i][j].iq,&a[i][j].eq,&a[i][j].aq);
           // a[i][j].maxx = max(a[i][j].iq,max(a[i][j].eq,a[i][j].aq));
        }
        sort(a[i] + 1,a[i] + 1 + t[i],cmp);
    }
    //sort(a + 1,a + 1 + n,cmp);
    scanf("%lld",&seed);
    ll lastans = 0;
    ll ans = 0;
    for (int i=1;i<=q;i++)
    {
        int IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
        int EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
        int AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
        //cout << IQ << " " << EQ << " " << AQ << " " << solve(IQ,EQ,AQ) << endl;
        lastans=solve(IQ,EQ,AQ);  // The answer to the i-th friend
        ans = (ans % mod + (lastans * fpow(seed,q - i)) % mod) % mod;
    }
    printf("%lld\n",ans);
    return 0;
}

