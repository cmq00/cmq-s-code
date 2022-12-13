#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int b[N];
int n;

int gcd(int n,int m)
{
    return m ? gcd(m,n % m):n;
}

int solve()
{
    sort(a,a + n);
    //unique(a,a + n);
    int m = unique(a,a + n) - a;
    //for(int i = 0;i < m;++i)
        //cout << a[i] << " ";
    //cout << endl;
    if(m == 1){
        if(a[0] == 1)   return 1;
        else    return 0;
    }
    else{
        b[0] = a[0];
        for(int i = 1;i < m;++i)
            b[i] = a[i] - a[i - 1];
        int g = 0;
        for(int i = 1;i < m;++i)
            g = gcd(g,b[i]);

        /*for(int i = 0;i < m;++i)
            cout << b[i] << " ";
        cout << endl;
        cout << "g: " << g << endl; */
        if(g == 1)
            return -1;
        if(gcd(g,b[0]) > 1)
            return 0;
        int ans = 1e9;
        /*for(int i = 1;i <= sqrt(g);++i){
            if(g % i == 0){
                int x = i,y = g / i;
                if(x > 1){
                    int k = b[0] / x + b[0] % x;
                    ans = min(ans,k * x - b[0]);
                }
                if(y > 1){
                    int k = b[0] / y + b[0] % y;
                    ans = min(ans,k * y - b[0]);
                }
            }
        }*/
        for(int i = 2;i < 1e5;++i){
            if(g % i == 0){
                g = i;
                break;
            }
        }
        ans = g - b[0] % g;
        return ans;
    }
}

int main()
{
    int t,cont = 1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        int ans = solve();
        printf("Case %d: ",cont++);
        printf("%d\n",ans);
    }
    return 0;
}